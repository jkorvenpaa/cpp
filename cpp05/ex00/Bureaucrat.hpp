#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string &name,int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	const std::string	getName();
	int	getGrade();
	void incrementGrade();
	void decrementGrade();

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
std::ostream& operator<<(std::ostream &os, const Bureaucrat current);
