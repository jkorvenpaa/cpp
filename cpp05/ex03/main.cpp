#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){

try
{
	AForm* rrf;
	Intern someRandomIntern;
	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	Bureaucrat b("Peter", 137);
	// b.decrementGrade();
	//b.incrementGrade();
	std::cout << *rrf;
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
std::cout << std::endl;

try
{
	AForm* rob;
	Intern someRandomIntern;
	Bureaucrat b("Peter", 45);
	// b.decrementGrade();
	//b.incrementGrade();
	rob = someRandomIntern.makeForm("RobotomyRequestForm", "Robo");
	std::cout << *rob;
	b.signForm(*rob);
	b.executeForm(*rob);
	delete rob;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
std::cout << std::endl;

try
{
	AForm* pres;
	Intern someRandomIntern;
	Bureaucrat b("Peter", 5);
	// b.decrementGrade();
	//b.incrementGrade();
	pres = someRandomIntern.makeForm("PresidentialPardonForm", "Pressa");
	std::cout << *pres;
	b.signForm(*pres);
	b.executeForm(*pres);
	delete pres;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}

return 0;
}