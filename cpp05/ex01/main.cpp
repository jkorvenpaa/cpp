#include "Bureaucrat.hpp"

int main(void){

try
{
	Bureaucrat b("Nuria", 1);
	Bureaucrat c(b);
	c.decrementGrade();
	std::cout << c << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}

try
{
	Bureaucrat b("Peter", 10);
	Form form("AI policy", 10, 1);
	std::cout << form << std::endl;
	b.signForm(form);
	std::cout << form << std::endl;
	b.signForm(form);
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
	std::cout << e.what() << std::endl;
}
	return 0;
}