#include "ScalarConverter.hpp"

static void	intLiteral(std::string literal){
	std::cout << literal << std::endl;

}
static void	floatLiteral(std::string literal){
	std::cout << literal << std::endl;
}

static void	doubleLiteral(std::string literal){
	std::cout << literal << std::endl;
}

static void	charLiteral(std::string literal){
	std::cout << literal << std::endl;
}

static void	invalid(std::string literal){
	std::cout << literal << std::endl;
}

void ScalarConverter::setType(std::string literal){

	int i = 0;
	
	if ((int)literal.length() == 1){
		if (std::isdigit(literal[i]))
			_type = INT;
		else if (std::isprint(literal[i]))
			_type = CHAR;
		else
			_type = INVALID;
		return ;
	}

	int dot = 0;
	for (int i = 0; i < (int)literal.length(); i++){
		if (!std::isdigit(literal[i])){
			if (literal[i] == '.'){
				dot++;
				continue;
			}
			if (literal[i] == 'f' && i == (int)literal.length() - 1 && dot <= 1){
				_type = FLOAT;
				return ;
			}
			else{
				_type = INVALID;
				return ;
			}
		}
	}
	if (dot == 1)
		_type = DOUBLE;
	else if (dot == 0)
		_type = INT;
	else
		_type = INVALID;
}


void ScalarConverter::convert(std::string literal){

	setType(literal);
	switch(_type)
	{
		case 0:
			charLiteral(literal);
			break ;
		case 1:
			intLiteral(literal);
			break ;
		case 2:
			floatLiteral(literal);
			break ;
		case 3:
			doubleLiteral(literal);
			break ;
		default:
			invalid(literal);
	}
	
}


