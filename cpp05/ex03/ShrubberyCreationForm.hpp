#pragma once
#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
std::string _target;
	
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	void execute(Bureaucrat const &executor) const override;
};


