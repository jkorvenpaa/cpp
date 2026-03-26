#pragma once

#include <iostream>
#include <regex>
#include <climits>
#include <limits>

class ScalarConverter
{
private:
	enum Type{
		 CHAR,
		 INT,
		 FLOAT,
		 DOUBLE,
		 NAN,
		 INFPOS,
		 INFNEG,
		 NANF,
		 INFFPOS,
		 INFFNEG,
		 INVALID,

	};
	static Type setType(const std::string &literal);

public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter	&operator=(const ScalarConverter &other) = delete;
	
	static void convert(const std::string &literal);
};


