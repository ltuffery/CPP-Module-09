#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <string>
#include <regex.h>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string file): _file(file)
{
	this->_loadDataFile();
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

	std::getline(istr, str);
	
	if (str != "date,exchange_rate")
	{
		throw std::runtime_error("invalid data.csv header");
	}

	std::getline(istr, str);
	
	while (!str.empty())
	{
		if (!this->_regex(str, "^(((\\d{2})(([02468][048])|([13579][26]))-02-29)|((([0-9][0-9])([0-9][0-9])))-((((0[0-9])|(1[0-2]))-((0[0-9])|(1[0-9])|(2[0-8])))|((((0[13578])|(1[02]))-31)|(((0[1,3-9])|(1[0-2]))-(29|30))))),[0-9]+(\\.([0-9]{1,}))?$"))
		{
			throw std::runtime_error("Error in format line : " + str);
		}
		std::getline(istr, str);
	}
}
