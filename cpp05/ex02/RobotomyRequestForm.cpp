#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("name", 72, 45), _target("")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other._target, 72, 45), _target(other._target){

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw FormNotSignedException("Unsigned form can not be executed");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(executor.getName() + "'s grade is too low to execute");

    if (rand()%2 == 0)
        std::cout << "Brrr… BRRRR… brrrrrr… DRRRRRRRRRR!\n" << _target
        << " has been robotomized successfully\n";
    else
        std::cout <<  _target << " the robotomy failed\n";
}