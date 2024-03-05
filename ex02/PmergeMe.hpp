#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

	public:
		PmergeMe();
		~PmergeMe();
		template<typename T>
		static void parsing(char **av, T &arr)
		{
			for (size_t i = 1; av[i] != NULL; i++)
			{
				if (!isStrDigit(av[i]))
				{
					throw std::runtime_error("Is not digit");
				}
				arr.push_back(std::atoi(av[i]));
			}
		}

		template<typename T>
		static std::vector<std::pair<int, int> > createPair(T &arr, T &maxList)
		{
			std::vector<std::pair<int, int> > pairs;
			std::pair<int, int> pair;

			for (size_t i = 1; i < arr.size(); i += 2)
			{
				pair = std::make_pair(arr[i - 1], arr[i]);

				maxList.push_back(std::max(pair.first, pair.second));
				pairs.push_back(pair);
			}

			return pairs;
		}

		template<typename T>
		static int binarySearch(T &arr, int start, int end, int n)
		{
        	int mid = start + (end - start) / 2;
			
			if (start <= end) {
				if (arr[mid] < n)
				{
            		return binarySearch(arr, mid + 1, end, n);
        		} 
				else 
				{
            		return binarySearch(arr, start, mid - 1, n);
        		}
    		}

			return mid;
		}

		template<typename T>
		static int find(T &arr, int n)
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				if (arr[i] == n)
					return i;
			}

			return -1;
		}

		static bool isStrDigit(std::string s);
		static void mergeSort(std::vector<int>& array, int left, int right);
		static size_t findMinOf(int max, std::vector<std::pair<int, int> > pairs);
		static int jacobsthal(int n);
};

#endif
