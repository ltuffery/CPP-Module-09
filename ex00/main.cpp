#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		return 1;
	}

	BitcoinExchange btex(av[1]);
}
