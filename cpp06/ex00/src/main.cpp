#include "ScalarConverter.hpp"

int	main(int argc, char **argv){

	if (argc != 2)
		std::cout << "Usage: ./converter <literal>\n";
	else{
		std::string lit = argv[1];
		ScalarConverter::convert(lit);
	}
	return(0);
}

/*./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0*/