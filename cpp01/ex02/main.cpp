#include <iostream>

int	main(void){
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

//The memory address of the string variable.
	std::cout << &str << std::endl;
//The memory address held by stringPTR.
	std::cout << ptr << std::endl;
//The memory address held by stringREF.
	std::cout << &ref << std::endl;
//The value of the string variable.
	std::cout << str << std::endl;
//The value pointed to by stringPTR.
	std::cout << *ptr << std:: endl;
//The value pointed to by stringREF.
	std::cout << ref << std::endl;
}