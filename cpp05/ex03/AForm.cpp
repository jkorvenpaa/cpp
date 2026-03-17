#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("name"),_signed(false), _gradeToSign(1), _gradeToExecute(1){

}

AForm::~AForm()
{
}
AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
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

AForm::AForm(const AForm &other):_name(other._name),_signed(other._signed),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){

}

AForm &AForm::operator=(const AForm &other){
	if (this != &other){
		_signed = false;
	}
	return *this;
}


std::string	AForm::getName() const{
	return _name;
}
int	AForm::getGradeToSign() const{
	return _gradeToSign;
}
int	AForm::getGradeToExecute() const{
	return _gradeToExecute;
}
bool AForm::getSigned() const{
	return _signed;
}

std::ostream& operator<<(std::ostream &os, const AForm& form){
	os << std::endl << GREEN << "Form "<< form.getName() << std::endl << "Grade to sign: " << form.getGradeToSign() 
	<< std::endl << "Grade to execute: "<< form.getGradeToExecute() << std::endl;
	
	if (form.getSigned())
		std::cout << "Form is Signed\n" << RESET;
	else
		std::cout << "Form is not Signed\n" << RESET;
	return os;
}

void	AForm::beSigned(Bureaucrat& signer){
	if (signer.getGrade() > _gradeToSign)
		throw GradeTooLowException(" grade is too low to sign ");
	_signed = true;
}


const char* AForm::GradeTooHighException:: what() const noexcept{
	return _message.c_str();
}

const char* AForm::GradeTooLowException:: what() const noexcept{
	return _message.c_str();
}

const char* AForm::FormNotSignedException:: what() const noexcept{
	return _message.c_str();
}
AForm::GradeTooHighException::GradeTooHighException(const std::string &message): _message(message){

}
AForm::GradeTooLowException::GradeTooLowException(const std::string &message): _message(message){

}
AForm::FormNotSignedException::FormNotSignedException(const std::string &message): _message(message){

}
