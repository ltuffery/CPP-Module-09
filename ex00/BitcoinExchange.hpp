#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{

	private:
		std::map<std::string, float> _c;
		const std::string _file;
		std::ifstream _fileStream;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(const BitcoinExchange &);

		void _loadDataFile();
		void _loadInputFile();
		bool _regex(std::string, std::string);

	public:
		BitcoinExchange(const std::string);
		~BitcoinExchange();

		void run();

};

#endif
