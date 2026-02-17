#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	std::cout << "WrongCat Default constructor called\n";
	_type = "WrongCat";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy){
	_type = copy._type;
	std::cout << "WrongCat Copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
	std::cout << "WrongCat Copy assignment operator called\n";
	_type = copy._type;
	return *this;
}
void	WrongCat::makeSound() const{
	std::cout << _type << " makes sound: Wrong Mauu" << std::endl;
}