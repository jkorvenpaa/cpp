#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Animal Default constructor called\n";
}

Animal::~Animal(){
	std::cout << "Animal Destructor called\n";
}

std::string Animal::getType()const{
	return _type;
}

Animal::Animal(const Animal &copy){
	_type = copy._type;
	std::cout << "Animal Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &copy){
	std::cout << "Animal Copy assignment operator called\n";
	if (this != &copy)
		_type = copy._type;
	return *this;
}
void	Animal::makeSound() const{
    std::cout << _type <<" makes sound: Animal sound" << std::endl;
}