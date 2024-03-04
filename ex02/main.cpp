#include "PmergeMe.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

void vectorSort(char **av)
{
	std::vector<int> c;
	std::vector<int> maxList;

	PmergeMe::parsing(av, c);

	std::vector<std::pair<int, int> > pairs = PmergeMe::createPair(c, maxList);
	PmergeMe::mergeSort(maxList, 0, maxList.size() - 1);

	maxList.insert(maxList.begin(), PmergeMe::findMinOf(maxList[0], pairs));

	for (int i = 1; i < 10; i++)
		std::cout << "num : " << PmergeMe::jacobsthal(i) * 2 << std::endl;
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
