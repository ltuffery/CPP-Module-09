#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
# include <string>
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
		static std::vector<std::pair<int, int>> createPair(T &arr)
		{
			std::vector<std::pair<int, int>> pairs;
			T nArr;

			for (size_t i = 0; i < arr.size(); i += 2)
			{
				nArr.push_back(std::max(arr[i], arr[i + 1]));
				pairs.push_back(std::make_pair(std::max(arr[i], arr[i + 1]), std::min(arr[i], arr[i + 1])));
			}

			return pairs;
		}

		static bool isStrDigit(std::string s);
		static void sortMax(std::vector<std::pair<int, int>>);
};

#endif
