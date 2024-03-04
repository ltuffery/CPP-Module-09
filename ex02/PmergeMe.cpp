#include "PmergeMe.hpp"

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

void PmergeMe::mergeSort(std::vector<int>& array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		std::vector<int> tempArray(right - left + 1);
		std::merge(array.begin() + left, array.begin() + mid + 1,
				array.begin() + mid + 1, array.begin() + right + 1,
				tempArray.begin());

		std::copy(tempArray.begin(), tempArray.end(), array.begin() + left);
    }
}

size_t PmergeMe::findMinOf(int max, std::vector<std::pair<int, int> > pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == max || pairs[i].second == max)
		{
			return std::min(pairs[i].first, pairs[i].second);
		}
	}

	return -1;
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}
