#include "Dog.hpp"

Dog::Dog(): Animal(){
	std::cout << "Dog Default constructor called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog Destructor called\n";
	delete _brain;
}

Dog::Dog(const Dog &copy): Animal(copy){
	
	_brain = new Brain(*copy._brain);
	std::cout << "Dog Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy){
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &copy){
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}
void	Dog::makeSound()const{
	std::cout << _type << " makes soud: Wuff" << std::endl;
}