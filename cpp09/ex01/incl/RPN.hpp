#pragma once
#include <iostream>
#include <stack>
#include <sstream>


class RPN{
	private:
		std::stack<int> _numbers;
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN&	operator=(const RPN &other);
		void	calculateRPN(std::string arg);

};