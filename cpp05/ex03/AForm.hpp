#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[92m"

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
public:
	AForm();
	virtual ~AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat& signer);
	virtual void execute(Bureaucrat const & executor) const = 0;
	
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
	class FormNotSignedException : public std::exception{
		private:
			std::string _message;
		public:
			FormNotSignedException(const std::string &message);
			const char* what() const noexcept override;
	};
};
std::ostream& operator<<(std::ostream &os, const AForm& bc);

