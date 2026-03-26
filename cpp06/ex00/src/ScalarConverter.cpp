#include "ScalarConverter.hpp"

 static void intLimits(double value){
	if ((value >= (static_cast <double> (INT_MIN))) && (value <= (static_cast <double> (INT_MAX))))
		std::cout << "int " << static_cast <int>(value) << std::endl;
	else
		std::cout << "int imbossible" << std::endl;
}

 static void floatLimits(double value){
	if (value < (static_cast <double> (std::numeric_limits<float>::min())))
		std::cout << "float -inff"<< std::endl;
	else if (value > (static_cast <double> (std::numeric_limits<float>::max())))
		std::cout << "float +inff"<< std::endl;
	else
		std::cout << "float " << static_cast <float>(value) << std::endl;
}

static void	charLiteral(const std::string &literal){
	std::cout << "char " <<  literal << std::endl;
	std::cout << "int " << static_cast <int>(literal[0]) <<std::endl;
	std::cout << "float " << static_cast <float> (literal[0]) << std::endl;
	std::cout << "double "<< static_cast <double> (literal[0])<< std::endl;
}

static void	doubleLiteral(const double &value){
	std::cout << "char imbossible" << std::endl;
	intLimits(value);
	floatLimits(value);
	std::cout << "double "<< value << std::endl;
}
static void specialLiterals(const std::string special){
	std::cout << "char imbossible" << std::endl;
	std::cout << "int imbossible" << std::endl;
	std::cout << "float " << special << "f" << std::endl;
	std::cout << "double " << special << std::endl;
}

static void	invalid(const std::string &literal){
	std::cout << "invalid input "<< literal << std::endl;
}

ScalarConverter::Type ScalarConverter::setType(const std::string &literal){

	std::regex rchar("^.$");
	std::regex rint("^(\\+|\\-)?\\d+$");
	std::regex rfloat("^(\\+|\\-)?(\\d+|\\d+\\.|\\d+\\.\\d+|\\.\\d+)f$");
	std::regex rdouble("^(\\+|\\-)?(\\d+|\\d+\\.|\\d+\\.\\d+|\\.\\d+)$");
	std::regex rnan("^nan$");
	std::regex rinfpos("^\\+inf$");
	std::regex rinfneg("^-inf$");
	std::regex rnanf("^nanf$");
	std::regex rinffpos("^\\+inff$");
	std::regex rinffneg("^-inff$");
	
	if (std::regex_match(literal, rint))
		return INT;
	if(std::regex_match(literal, rchar))
		return CHAR;
	if (std::regex_match(literal, rfloat))
		 return FLOAT;
	if (std::regex_match(literal, rdouble))
		 return DOUBLE;
	if (std::regex_match(literal, rnan))
		return NAN;
	if (std::regex_match(literal, rinfpos))
		return INFPOS;
	if (std::regex_match(literal, rinfneg))
		return  INFNEG;
	if (std::regex_match(literal, rnanf))
		return  NANF;
	if (std::regex_match(literal, rinffpos))
		return  INFFPOS;
	if (std::regex_match(literal, rinffneg))
		return  INFFNEG;
	else
		 return INVALID;
}


void ScalarConverter::convert(const std::string &literal){

	Type type = setType(literal);
	double value;
	switch(type)
	{
		case CHAR:
			charLiteral(literal);
			break ;
		case INT:
		case FLOAT:
		case DOUBLE:
			try{
				value = std::stod(literal);
				doubleLiteral(value);
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << "std::stod invalid_argument" << std::endl;
			}
			catch(const std::out_of_range& e){
				std::cout << "std::stod out_of_range\n" << std::endl;
			}
			break ;
		case NAN:
		case NANF:
			specialLiterals("nan");
			break;
		case INFPOS:
		case INFFPOS:
			specialLiterals("+inf");
			break;
		case INFNEG:
		case INFFNEG:
			specialLiterals("-inf");
			break;
		default:
			invalid(literal);
	}
	
}


