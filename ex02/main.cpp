#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>

void vectorSort(char **av)
{
	std::vector<int> c;

	PmergeMe::parsing(av, c);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Invalide arguments size" << std::endl;
		return 1;
	}

	try
	{
		vectorSort(av);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}
