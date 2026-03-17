#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	~Intern();
	AForm*	makeForm(const std::string name, const std::string target);
	void 	noForm();

	class NoFormException : public std::exception{
		private:
			std::string _message;
		public:
			NoFormException(const std::string &message);
			const char* what() const noexcept override;
	};
};


