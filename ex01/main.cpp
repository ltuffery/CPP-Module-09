#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

static void parse(std::string line)
{
	if (line.empty())
	{
		throw std::runtime_error("Error: parsing");
	}
	
	bool is_full_space = true;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ' && i > 0)
		{
			is_full_space = false;
			if (line[i - 1] != ' ')
			{
				throw std::runtime_error("Error: parsing");
			}
		}
	}

	if (is_full_space)
	{
		throw std::runtime_error("Error: parsing");
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "I only take 1 argument" << std::endl;
		return 1;
	}

	try
	{
		parse(av[1]);

		RPN rpn(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
