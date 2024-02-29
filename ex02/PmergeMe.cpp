#include "PmergeMe.hpp"
#include <cstddef>

bool PmergeMe::isStrDigit(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}
