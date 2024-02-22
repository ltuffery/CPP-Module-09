#include "RPN.hpp"
#include <cstddef>
#include <string>
#include <stdexcept>
#include <iostream>

RPN::RPN(const std::string line)
{
	for (size_t i = 0; i < line.length(); i++)
	{
		if (this->is_operator(line[i]))
		{
			this->calc(line[i]);
		}
		else if (line[i] == ' ')
		{
			continue;
		}
		else
		{
			this->_c.push(line[i] - '0');
		}
	}

	if (this->_c.size() > 1)
	{
		throw std::runtime_error("Error: There are still numbers in the stack");
	}

	std::cout << this->_c.top() << std::endl;
}

bool RPN::is_operator(char c)
{
	switch (c) {
		case '/':
		case '*':
		case '+':
		case '-':
			return true;
		default:
			return false;
	}
}

void RPN::calc(char c)
{
	if (this->_c.size() < 2)
	{
		throw std::runtime_error("Error: Size < 2");
	}

	int last = this->_c.top();
	this->_c.pop();
	int first = this->_c.top();
	this->_c.pop();

	switch (c) {
		case '+':
			this->_c.push(first + last);
			break;
		case '-':
			this->_c.push(first - last);
			break;
		case '*':
			this->_c.push(first * last);
			break;
		default:
			this->_c.push(first / last);
			break;
	}
}
