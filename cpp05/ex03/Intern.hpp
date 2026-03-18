#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);
	AForm*	makeForm(const std::string name, const std::string target);

	class NoFormException : public std::exception{
		private:
			std::string _message;
		public:
			NoFormException(const std::string &message);
			const char* what() const noexcept override;
	};
};


