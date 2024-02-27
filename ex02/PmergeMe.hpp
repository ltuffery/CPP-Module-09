#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cctype>
#include <cstddef>
#include <sstream>
#include <stdexcept>
# include <string>

class PmergeMe
{
	public:
		template<typename T>
		static void parsing(std::string line, T &arr)
		{
			for (size_t i = 0; i < line.length(); i++)
			{
				if (!std::isdigit(line[i]))
				{
					throw std::runtime_error("Is not digit");
				}

			}
		}
};

#endif
