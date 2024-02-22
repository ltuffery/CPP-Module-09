#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		return 1;
	}

	try 
	{
		BitcoinExchange btex(av[1]);

		btex.run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
