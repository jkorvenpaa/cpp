#include "PmergeMe.hpp"

int	main (int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error\n";
		return 1;
	}
	try{
		PmergeMe pmerge;
		pmerge.parseInput(argc, argv);
		pmerge.processVector();
		pmerge.processDeque();
		
	}
	catch (std::exception &e){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}