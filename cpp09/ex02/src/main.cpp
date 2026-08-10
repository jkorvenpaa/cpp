#include "PmergeMe.hpp"

int	main (int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: not enough arguments\n";
		return 1;
	}
	try{
		PmergeMe pmerge;
		pmerge.parseInput(argc, argv);
		pmerge.processVector();
		pmerge.processDeque();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}