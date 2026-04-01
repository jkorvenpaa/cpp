#include "ScalarConverter.hpp"

 static void intLimits(double value){
	if ((value >= (static_cast <double> (INT_MIN))) && (value <= (static_cast <double> (INT_MAX))))
		std::cout << "int " << static_cast <int>(value) << std::endl;
	else
		std::cout << "int impossible" << std::endl;
}

static void floatLimits(double value){
	if (value < (static_cast <double> (std::numeric_limits<float>::lowest())))
		std::cout << "float impossible"<< std::endl;
	else if (value > (static_cast <double> (std::numeric_limits<float>::max())))
		std::cout << "float impossible"<< std::endl;
	else{
		double dub = std::round(value);
		if (dub == value)
			std::cout << "float " << static_cast <float>(value) << ".0f" <<std::endl;
		else
			std::cout << "float " << static_cast <float>(value) << "f"<< std::endl;
	}
 }

static void	charLiteral(const std::string &literal){
	std::cout << "char " <<  literal << std::endl;
	std::cout << "int " << static_cast <int>(literal[0]) <<std::endl;
	std::cout << "float " << static_cast <float> (literal[0]) << std::endl;
	std::cout << "double "<< static_cast <double> (literal[0])<< std::endl;
}

static void charLimits(const double &value){
	double dub = std::round(value);
	if ((value >= 32 && value <=126) && (dub == value))
		std::cout << "char " << static_cast<char>(value) << std::endl;
	else if ((value >= 0 && value <=255) && (dub == value))
		std::cout << "char non displayable" << std::endl;
	else
		std::cout << "char impossible" << std::endl;
}

static void	doubleLiteral(const double &value){
	double dub = std::round(value);
	charLimits(value);
	intLimits(value);
	floatLimits(value);
	if (dub == value)
		std::cout << "double "<< value << ".0"<<std::endl;
	else
		std::cout << "double "<< value <<std::endl;
}
static void pseudoLiterals(const std::string special){
	std::cout << "char impossible" << std::endl;
	std::cout << "int impossible" << std::endl;
	std::cout << "float " << special << "f" << std::endl;
	std::cout << "double " << special << std::endl;
}

static void	invalid(const std::string &literal){
	std::cout << "invalid input "<< literal << std::endl;
}
static void doubleLimits(const std::string &literal){
	std::cout << "char impossible" << std::endl;
	std::cout << "int impossible" << std::endl;
	std::cout << "float impossible" << std::endl;
	if (literal[0] == '-')
		std::cout << "double -inf" << std::endl;
	else
		std::cout << "double +inf" << std::endl;
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
	if(std::regex_match(literal, rchar)){
		if (std::isprint(literal[0]))
			return CHAR;
		else 
			return INVALID;
	}
	if (std::regex_match(literal, rfloat))
		 return FLOAT;
	if (std::regex_match(literal, rdouble))
		 return DOUBLE;
	if (std::regex_match(literal, rnan))
		return NANN;
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
				invalid(literal);
			}
			catch(const std::out_of_range& e){
				doubleLimits(literal);
			}
			break ;
		case NANN:
		case NANF:
			pseudoLiterals("nan");
			break;
		case INFPOS:
		case INFFPOS:
			pseudoLiterals("+inf");
			break;
		case INFNEG:
		case INFFNEG:
			pseudoLiterals("-inf");
			break;
		default:
			invalid(literal);
	}
}


