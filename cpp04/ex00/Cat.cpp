#include "Cat.hpp"

Cat::Cat(): Animal(){
	std::cout << "Cat Default constructor called\n";
	_type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat Destructor called\n";
}

Cat::Cat(const Cat &copy): Animal(copy){
	_type = copy._type;
	std::cout << "Cat  Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &copy){
	std::cout << "Cat Copy assignment operator called\n";
	_type = copy._type;
	return *this;
}
void	Cat::makeSound() const{
	std::cout << _type << " makes sound: Mauu" << std::endl;
}