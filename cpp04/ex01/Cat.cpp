#include "Cat.hpp"

Cat::Cat(): Animal(){
	std::cout << "Cat Default constructor called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat Destructor called\n";
	delete _brain;
}

Cat::Cat(const Cat &copy): Animal(copy){
	_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &copy){
	std::cout << "Cat Copy assignment operator called\n";
	if (this != &copy){
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}
void	Cat::makeSound() const{
	std::cout << _type << " makes sound: Mauu" << std::endl;

}

std::string	Cat::brain(std::string idea){
	_brain->set_ideas(idea, 0);
	return _brain->get_ideas(0);
}