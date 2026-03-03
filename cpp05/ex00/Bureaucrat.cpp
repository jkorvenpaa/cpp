#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade){
	std::cout << "Bureaucrat constructor called\n";
	if (grade > 150)
		throw GradeTooLowException(_name + ": Grade too LOW\n");
	if (grade < 1)
		throw GradeTooHighException(_name + ": Grade too HIGH\n");
	std::cout << _name << " has grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade){
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	std::cout << "Bureaucrat assignment operator called\n";
	if (this != &other){
		_grade = other._grade;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &os, Bureaucrat& current){
	std::cout << current.getName() << ", bureaucrat grade " << current.getGrade();
	return os;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message): _message(message){

}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message): _message(message){

}

const std::string	Bureaucrat::getName(){
	return _name;
}
int	Bureaucrat::getGrade(){
	return _grade;
}

const char* Bureaucrat::GradeTooHighException:: what() const noexcept{
	return _message.c_str();
}

const char* Bureaucrat::GradeTooLowException:: what() const noexcept{
	return _message.c_str();
}
void Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw GradeTooHighException(_name + ": Grade too HIGH\n");
	_grade--;

}
void Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException(_name + ": Grade too LOW\n");
	_grade++;
	
}
