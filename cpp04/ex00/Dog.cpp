#include "Dog.hpp"

Dog::Dog(): Animal(){
	std::cout << "Dog Default constructor called\n";
	_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog Destructor called\n";
}

Dog::Dog(const Dog &copy): Animal(copy){
	_type = copy._type;
	std::cout << "Cat  Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy){
	std::cout << "Cat Copy assignment operator called\n";
	_type = copy._type;
	return *this;
}
void	Dog::makeSound()const{
	std::cout << _type << " makes soud: Wuff" << std::endl;
}