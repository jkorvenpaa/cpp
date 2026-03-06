#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("name"),_signed(false), _gradeToSign(1), _gradeToExecute(1){

}

Form::~Form()
{
}
Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name),_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign > 150)
		throw GradeTooLowException(_name + ": GradeToSign too LOW\n");
	if (gradeToSign < 1)
		throw GradeTooHighException(_name + ": GradeToSign too HIGH\n");
	if (gradeToExecute > 150)
		throw GradeTooLowException(_name + ": GradeToExecute too LOW\n");
	if (gradeToExecute < 1)
		throw GradeTooHighException(_name + ": GradeToExecute too HIGH\n");
}

Form::Form(const Form &other):_name(other._name),_signed(other._signed),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){

}

Form &Form::operator=(const Form &other){
	if (this != &other){
		_signed = false;
	}
	return *this;
}


std::string	Form::getName() const{
	return _name;
}
int	Form::getGradeToSign() const{
	return _gradeToSign;
}
int	Form::getGradeToExecute() const{
	return _gradeToExecute;
}
bool Form::getSigned() const{
	return _signed;
}

std::ostream& operator<<(std::ostream &os, const Form& form){
	os << "Form "<< form.getName() << std::endl << "Grade to sign: " << form.getGradeToSign() 
	<< std::endl << "Grade to execute: "<< form.getGradeToExecute() << std::endl;
	
	if (form.getSigned())
		std::cout << "Form is Signed\n";
	else
		std::cout << "Form is not Signed\n";
	return os;
}

void	Form::beSigned(Bureaucrat& signer){
	if (signer.getGrade() > _gradeToSign)
		throw GradeTooLowException(" grade is too low to sign ");
	_signed = true;
}


const char* Form::GradeTooHighException:: what() const noexcept{
	return _message.c_str();
}

const char* Form::GradeTooLowException:: what() const noexcept{
	return _message.c_str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string &message): _message(message){

}
Form::GradeTooLowException::GradeTooLowException(const std::string &message): _message(message){

}