#include "RPN.hpp"

int main (int ac, char **av){
	if (ac != 2){
		std::cerr << "Error: argument count is not 2\n";
		return 1;
	}
	RPN rpn;
    try{
	    rpn.calculateRPN(av[1]);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
	return 0;
}