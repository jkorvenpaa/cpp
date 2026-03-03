#include "Bureaucrat.hpp"

int main(void){

Bureaucrat B("Peter", 1);
try
{
	B.decrementGrade();
	B.incrementGrade();
	B.incrementGrade();
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
	return 0;
}