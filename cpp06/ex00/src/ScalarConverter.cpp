#include "ScalarConverter.hpp"

/*	int i = std::stoi(lit);
	float f = std::stof(lit);
	double d = std::stod(lit);*/

static void	charLiteral(const std::string &lit){

	std::cout << "char " <<  lit << std::endl;
	std::cout << "int " << static_cast <int>(lit[0]) <<std::endl;
	std::cout << "float " << static_cast <float> (lit[0]) << std::endl;
	std::cout << "double "<< static_cast <double> (lit[0])<< std::endl;
}

static void	intLiteral(const double &value){

	std::cout << "char invalid" << std::endl;
	std::cout << "int " << static_cast <int>(value) << std::endl;
	std::cout << "float " << static_cast <float>(value) << std::endl;
	std::cout << "double "<< value << std::endl;

}
static void	floatLiteral(const double &lit){
	std::cout << "float " << lit << std::endl;
}

static void	doubleLiteral(const double &lit){
	std::cout << "double "<< lit << std::endl;
}

static void	invalid(const std::string &lit){
	std::cout << "invalid "<< lit << std::endl;
}

ScalarConverter::Type ScalarConverter::setType(const std::string &literal){

	int i = 0;
	if ((int)literal.length() == 1){
		if (std::isdigit(literal[i]))
			return INT;
		else if (std::isprint(literal[i]))
			return CHAR;
		else
			return INVALID;
	}

	int dot = 0;
	for (int i = 0; i < (int)literal.length(); i++){
		if (!std::isdigit(literal[i])){
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				continue;
			if (literal[i] == '.' && i > 0){
				dot++;
				continue;
			}
			if (literal[i] == 'f' && i == (int)literal.length() - 1 && dot <= 1){
				return FLOAT;
			}
			else{
				return INVALID;
			}
		}
	}
	if (dot == 1)
		return DOUBLE;
	else if (dot == 0)
		return INT;
	else
		return INVALID;
}


void ScalarConverter::convert(const std::string &literal){

	Type type = setType(literal);
	double value;
	switch(type)
	{
		case 0:
			charLiteral(literal);
			break ;
		case 1:
			value = stod(literal);
			intLiteral(value);
			break ;
		case 2:
			value = stod(literal);
			floatLiteral(value);
			break ;
		case 3:
			value = stod(literal);
			doubleLiteral(value);
			break ;
		default:
			invalid(literal);
	}
	
}


