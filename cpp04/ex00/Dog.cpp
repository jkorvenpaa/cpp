#include "Dog.hpp"

Dog::Dog(): Animal(){
	std::cout << "Dog Default constructor called\n";
	_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog Destructor called\n";
}

Dog::Dog(const Dog &copy): Animal(copy){	
	std::cout << "Dog Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy){
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}
void	Dog::makeSound()const{
	std::cout << _type << " makes soud: Wuff" << std::endl;
}