#include "RPN.hpp"

int main (int ac, char **av){
	if (ac != 2){
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	RPN rpn;
	rpn.calculateRPN(av[1]);
	return 0;
}