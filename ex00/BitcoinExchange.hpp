#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{

	private:
		std::map<std::string, float> _c;
		const std::string _file;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(const BitcoinExchange &);

		void _loadDataFile();
		bool _regex(std::string, std::string);

	public:
		BitcoinExchange(const std::string);
		~BitcoinExchange();

};

#endif
