#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("name"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade){
	//std::cout << "Bureaucrat constructor called\n";
	if (grade > 150)
		throw GradeTooLowException(_name + ": Grade too LOW\n");
	if (grade < 1)
		throw GradeTooHighException(_name + ": Grade too HIGH\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade){
	//std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	//std::cout << "Bureaucrat assignment operator called\n";
	if (this != &other){
		_grade = other._grade;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &os, const Bureaucrat& bc){
	os << "Bureaucrat "<< bc.getName() << " has grade " << bc.getGrade();
	return os;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message): _message(message){

}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message): _message(message){

}

const std::string	Bureaucrat::getName() const{
	return _name;
}

int	Bureaucrat::getGrade() const{
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

void	Bureaucrat::signForm(AForm& form){
	
	if (form.getSigned()){
		std::cout << "Form is already signed\n";
		return ;
	}
	try{
		form.beSigned(*this);
		std::cout << _name << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << _name << "'s" << e.what()  << form.getName() << std::endl;
	}
}

void 	Bureaucrat::executeForm(AForm const &form){
	form.execute(*this);
	std::cout <<_name << " executed form " << form.getName() << std::endl;;
}