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
	Bureaucrat b("Peter", 151);
	b.decrementGrade();
	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
	return 0;
}