#pragma once
#include <iostream>

class Bureaucrat;
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
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &other);
	Form& operator=(const Form &other);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat& signer);
	

	class GradeTooHighException : public std::exception{
		private:
			std::string _message;
		public:
			GradeTooHighException(const std::string &message);
			const char* what() const noexcept override;
	};	
	class GradeTooLowException : public std::exception{
		private:
			std::string _message;
		public:
			GradeTooLowException(const std::string &message);
			const char* what() const noexcept override;
	};
};
std::ostream& operator<<(std::ostream &os, const Form& bc);

