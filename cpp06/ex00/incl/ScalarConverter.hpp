#pragma once

#include <iostream>
// #include <cstring>
// #include <cctype>

class ScalarConverter
{
private:
	enum Type{
		 CHAR,
		 INT,
		 FLOAT,
		 DOUBLE,
		 INVALID,
	};
	static Type _type;
	
public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter	&operator=(const ScalarConverter &other) = delete;
	
	static void setType(std::string literal);
	static void convert(std::string literal);
};


