#include "PmergeMe.hpp"

int	main (int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: not enough arguments\n";
		return 1;
	}
	try{
		parseInput(argc, argv);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}