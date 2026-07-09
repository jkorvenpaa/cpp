#pragma once
#include <iostream>
#include <stack>

class RPN{
	private:
		std::stack<int> _number;
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN&	operator=(const RPN &other);
		void	calculateRPN(std::string arg);

};