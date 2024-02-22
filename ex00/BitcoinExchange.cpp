#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
#include <regex.h>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string file): _file(file)
{
	this->_loadDataFile();
	this->_loadInputFile();
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::_regex(std::string str, std::string patern)
{
	regex_t reg;

	if (regcomp(&reg, patern.c_str(), REG_EXTENDED) != 0)
	{
		return false;
	}
	bool ret = regexec(&reg, str.c_str(), 0, NULL, 0) != REG_NOMATCH;
	regfree(&reg);
	return ret;
}

void BitcoinExchange::_loadDataFile()
{
	std::ifstream istr;

	istr.open("./data.csv");

	if (!istr.is_open())
	{
		throw std::runtime_error("error open data.csv");
	}

	std::string str;
	char *end;
	double n;

	std::getline(istr, str);
	
	if (str != "date,exchange_rate")
	{
		throw std::runtime_error("invalid data.csv header");
	}

	while (std::getline(istr, str))
	{
		if (!this->_regex(str, "^(((\\d{2})(([02468][048])|([13579][26]))-02-29)|((([0-9][0-9])([0-9][0-9])))-((((0[0-9])|(1[0-2]))-((0[0-9])|(1[0-9])|(2[0-8])))|((((0[13578])|(1[02]))-31)|(((0[1,3-9])|(1[0-2]))-(29|30))))),[0-9]+(\\.([0-9]{1,}))?$"))
		{
			throw std::runtime_error("Error in format line : " + str);
		}
		n = std::strtod(str.substr(11, str.length() - 1).c_str(), &end);
		this->_c.insert(std::pair<std::string, float>(str.substr(0, 10), static_cast<float>(n)));
	}
}

void BitcoinExchange::_loadInputFile()
{
	this->_fileStream.open(this->_file.c_str());

	if (!this->_fileStream.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
}

void BitcoinExchange::run()
{
	std::string str;

	std::getline(this->_fileStream, str);

	if (str != "date | value")
	{
		std::cout << "invalid header" << std::endl;
	}
	else
	{
		std::cout << str << std::endl;
	}

	std::string date;
	std::string value;
	char *end;

	while (std::getline(this->_fileStream, str))
	{
		if (!this->_regex(str, "^((([0-9][0-9])(([02468][048])|([13579][26]))-02-29)|((([0-9][0-9])([0-9][0-9])))-((((0[0-9])|(1[0-2]))-((0[0-9])|(1[0-9])|(2[0-8])))|((((0[13578])|(1[02]))-31)|(((0[1,3-9])|(1[0-2]))-(29|30)))))"))
		{
			std::cout << "Error: bad date" << std::endl;
			continue;
		}
		else if (str.substr(10, 3) != " | ")
		{
			std::cout << "Error: invalid separator" << std::endl;
			continue;
		}
		else if (!this->_regex(str.substr(13, str.length() - 1), "^([0-9]{1,3}(\\.[0-9]+)?)$|^1000$"))
		{
			std::cout << "Error: bad number" << std::endl;
			continue;
		}

		date = str.substr(0, 10);
		value = str.substr(13, str.length() - 1);

		std::map<std::string, float>::iterator it = this->_c.lower_bound(date);

		if (it == this->_c.end())
		{
			std::cout << "Error: Not exist" << std::endl;
			continue;
		}

		std::cout 
			<< date
			<< " => "
			<< value 
			<< " = ";

		if (this->_c.find(date) == this->_c.end())
		{
			it--;
		}

		std::cout << it->second * static_cast<float>(std::strtod(value.c_str(), &end)) << std::endl;
	}
}
