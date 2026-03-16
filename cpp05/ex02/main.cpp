#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){


// b.decrementGrade();
// b.incrementGrade();
try
{
	Bureaucrat b("Peter", 145);
	b.decrementGrade();
	//b.incrementGrade();
	ShrubberyCreationForm shrub("TreePolicy");
	std::cout << shrub;
	b.signForm(shrub);
	b.executeForm(shrub);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}

try
{
	Bureaucrat b("Peter", 72);
	b.decrementGrade();
	//b.incrementGrade();
	RobotomyRequestForm rob("Robo");
	std::cout << rob;
	b.signForm(rob);
	b.executeForm(rob);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
try
{
	Bureaucrat b("Peter", 72);
	b.decrementGrade();
	//b.incrementGrade();
	RobotomyRequestForm rob("Robo");
	std::cout << rob;
	b.signForm(rob);
	b.executeForm(rob);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}


try
{
	Bureaucrat b("Peter", 25);
	b.decrementGrade();
	//b.incrementGrade();
	PresidentialPardonForm pres("Pardon");
	std::cout << pres;
	b.signForm(pres);
	b.executeForm(pres);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
	return 0;
}