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

	std::vector<int> sorted = maxList;
	int index = 1;
	size_t js = PmergeMe::jacobsthal(index) * 2;
	size_t total = js;
	int sortedIndex;

	while (sorted.size() < (pairs.size() * 2))
	{
		for (size_t tmp = 0; tmp < js; tmp++)
		{
			if ((1 + total - tmp) > pairs.size())
				continue;
			
			int min = PmergeMe::findMinOf(maxList[1 + total - tmp], pairs);
			sortedIndex = PmergeMe::find(sorted, maxList[1 + total - tmp]);
			int bIndex = PmergeMe::binarySearch(sorted, 0, sortedIndex, min);

			sorted.insert(sorted.begin() + bIndex, min);
		}
		index++;
		js = std::min(PmergeMe::jacobsthal(index) * 2, (int)pairs.size() - 1);
		total += js;
	}

	if (c.size() % 2)
	{
		int bIndex = PmergeMe::binarySearch(sorted, 0, sorted.size() - 1, c.back());

		sorted.insert(sorted.begin() + bIndex, c.back());
	}

	for (size_t i = 0; i < sorted.size(); i++)
	{
		std::cout << "max : " << sorted[i] << std::endl;
	}
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
