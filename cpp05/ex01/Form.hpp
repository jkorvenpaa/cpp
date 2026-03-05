#pragma once
#include <iostream>

class Form
{
private:
	const std::string _name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
public:
	Form();
	~Form();
	Form(const Form &other);
	Form& operator=(const Form &other);
};


