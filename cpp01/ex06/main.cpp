#include "Harl.hpp"

int	main(int argc, char **argv){

	Harl harl;

	if  (argc != 2){
		std::cerr << "Usage: " << argv[0] << " LEVEL \n";
		return 1;
	}
	std::string levels[4]{
		 "DEBUG",
		 "INFO",
		 "WARNING",
		 "ERROR"
	};

	std::string arg = argv[1];
	int count = 0;
	for (int i = 0; i < 4; i++){
		if (levels[i] == arg){
			count = i + 1;
		}
	}
	switch (count){
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
	}
	return 0;
}