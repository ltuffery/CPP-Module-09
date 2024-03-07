#include "PmergeMe.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <ctime>

void dequeSort(char **av)
{
	const std::clock_t cStart = std::clock();
	std::deque<int> c;
	std::deque<int> maxList;

	PmergeMe::parsing(av, c);

	std::vector<std::pair<int, int> > pairs = PmergeMe::createPair(c, maxList);
	PmergeMe::mergeSort(maxList, 0, maxList.size() - 1);

	maxList.insert(maxList.begin(), PmergeMe::findMinOf(maxList[0], pairs));

	std::deque<int> sorted = maxList;
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

	const std::clock_t cEnd = std::clock();

	std::cout 
		<< "Time to process a range of "
		<< sorted.size()
		<< " elements with std::deque : "
		<< 1000.0 * (cEnd - cStart) / CLOCKS_PER_SEC 
		<< "ms" 
		<< std::endl;
}

void vectorSort(char **av)
{
	const std::clock_t cStart = std::clock();
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

	const std::clock_t cEnd = std::clock();
	
	std::cout << "After : ";
	
	for (size_t i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted[i] << " ";
	}

	std::cout << std::endl;

	std::cout 
		<< "Time to process a range of "
		<< sorted.size()
		<< " elements with std::vector : "
		<< 1000.0 * (cEnd - cStart) / CLOCKS_PER_SEC 
		<< "ms" 
		<< std::endl;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cout << "Invalide arguments size" << std::endl;
		return 1;
	}

	try
	{
		std::cout << "Before : ";
		for (int i = 1; av[i] != NULL; i++)
		{
			std::cout << av[i] << " ";
		}
		std::cout << std::endl;
		vectorSort(av);
		dequeSort(av);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}
