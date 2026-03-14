#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){

try
{
	Bureaucrat b("Peter", 137);
	ShrubberyCreationForm shrub("TreePolicy");
	std::cout << GREEN << shrub << std::endl << RESET;
	//b.executeForm(form);
	//b.signForm(shrub);
	b.executeForm(shrub);
	// b.decrementGrade();
	// b.signForm(a);
	// std::cout << b << std::endl;
	// b.incrementGrade();
	// std::cout << b << std::endl;
	// b.incrementGrade();
	// std::cout << b << std::endl;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl << std::endl;
}
try
{
	Bureaucrat b("Peter", 5);
	PresidentialPardonForm pres("Pardon");
	std::cout << GREEN << pres << std::endl << RESET;
	//b.executeForm(form);
	b.signForm(pres);
	b.executeForm(pres);
	// b.decrementGrade();
	// b.signForm(a);
	// std::cout << b << std::endl;
	// b.incrementGrade();
	// std::cout << b << std::endl;
	// b.incrementGrade();
	// std::cout << b << std::endl;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl << std::endl;
}
	return 0;
}