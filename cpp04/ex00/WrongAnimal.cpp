#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Animal"){
	std::cout << "WrongAnimal Default constructor called\n";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called\n";
}

std::string WrongAnimal::getType()const{
	return _type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	_type = copy._type;
	std::cout << "WrongAnimal Copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	std::cout << "WrongAnimal Copy assignment operator called\n";
	if (this != &copy)
		_type = copy._type;
	return *this;
}
void	WrongAnimal::makeSound() const{
    std::cout << _type <<" makes sound: WrongAnimal sound" << std::endl;
}