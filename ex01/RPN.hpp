#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _c;

		RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);
		bool is_operator(char);
		void calc(char);
	
	public:
		RPN(const std::string);
};

#endif
