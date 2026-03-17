#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){


AForm* rrf = nullptr;

try
{
	Intern someRandomIntern;
	rrf = someRandomIntern.makeForm("", "Bender");
	Bureaucrat b("Peter", 137);
	//b.decrementGrade();
	//b.incrementGrade();
	std::cout << *rrf;
	b.signForm(*rrf);
	b.executeForm(*rrf);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
delete rrf;

AForm* rob = nullptr;
try
{
	Intern someRandomIntern;
	Bureaucrat b("Peter", 72);
	b.decrementGrade();
	//b.incrementGrade();
	rob = someRandomIntern.makeForm("RobotomyRequestForm", "Robo");
	std::cout << *rob;
	b.signForm(*rob);
	b.executeForm(*rob);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
delete rob;


AForm* pres = nullptr;
try
{
	Intern someRandomIntern;
	Bureaucrat b("Peter", 25);
	b.decrementGrade();
	//b.incrementGrade();
	pres = someRandomIntern.makeForm("PresidentialPardonForm", "Pressa");
	std::cout << *pres;
	b.signForm(*pres);
	b.executeForm(*pres);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
delete pres;

return 0;
}