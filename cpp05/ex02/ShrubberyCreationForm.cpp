#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("name", 145, 137), _target("")
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm(target, 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target){

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getSigned())
		throw FormNotSignedException("Unsigned form can not be executed");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException("Grade to execute is too low");
	std::ofstream outfile(_target +"_shrubbery");
	if (!outfile)
		throw std::runtime_error("failed to open file");

	outfile << "       _-_           _-_       \n";
	outfile << "    /~~   ~~\\     /~~   ~~\\    \n";
	outfile << " /~~         ~~\\ /~~         ~~\\\n";
	outfile << "{               }{   ()        }\n";
	outfile << " \\  _-     -_  / \\  _-     -_  /\n";
	outfile << "   ~  \\\\ //  ~     ~  \\\\ //  ~\n";
	outfile << "_- -   | | _- _ _- -   | | _- _\n";
	outfile << "  _ -  | |   -_   _ -  | |   -_\n";
	outfile << "      // \\\\           // \\\\\n";
	
}
