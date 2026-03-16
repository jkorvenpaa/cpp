#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("name", 25, 5), _target("")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm(target, 25, 5), _target(target){

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target){

}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	if (!getSigned())
		throw FormNotSignedException("Unsigned form can not be executed");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(executor.getName() + "'s grade is too low to execute");
	std::cout <<  _target << " has been pardoned by Zaphod Beeblebrox\n";
}