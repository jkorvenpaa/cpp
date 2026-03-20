#pragma once

#include <iostream>

class ScalarConverter
{
public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter	&operator=(const ScalarConverter &other) = delete;
	
	static void convert(std::string literal);
};


