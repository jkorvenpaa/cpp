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
	static Type setType(const std::string &literal);

public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter	&operator=(const ScalarConverter &other) = delete;
	
	static void convert(const std::string &literal);
};


