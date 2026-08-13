#include "RPN.hpp"

RPN::RPN(){

}
RPN::~RPN(){

}
RPN::RPN(const RPN &other):_numbers(other._numbers){

}
RPN&	RPN::operator=(const RPN &other){
	if (this != &other){
		_numbers = other._numbers;
	}
	return *this;
}

void	RPN::calculateRPN(std::string arg){
	std::stringstream stream(arg);
	std::string unit;
	long firstPop;
	long secondPop;
	while (stream >> unit){
		if (unit.length()!= 1)
			throw(std::runtime_error ("Error"));
		if (isdigit(unit[0])){
			long num = std::stol(unit);
			_numbers.push(num);
		}
		else if(unit[0] == '+' || unit[0] == '-' || unit[0] == '*'|| unit[0] == '/'){
			if (_numbers.size() < 2)
   				 throw(std::runtime_error("Error"));
			firstPop = _numbers.top();
			_numbers.pop();
			secondPop = _numbers.top();
			_numbers.pop();
			long res;
			switch(unit[0]){
				case '+':
					res = firstPop + secondPop;
					break;
				case '-':
					res = secondPop - firstPop;
					break;
				case '*':
					res = firstPop * secondPop;
					break;
				case '/':
					if (firstPop == 0)
						throw(std::runtime_error ("Error"));
					res = secondPop / firstPop;
					break;
			}
			_numbers.push(res);
		}
		else
			throw(std::runtime_error ("Error"));
	}
	if (_numbers.size() != 1)
		throw(std::runtime_error ("Error"));
	else
		std::cout << _numbers.top() << std::endl;
}