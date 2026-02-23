#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";	
}

Brain::~Brain(){
	std::cout << "Brain Destructor called\n";
}

Brain::Brain(const Brain &copy){
	std::cout << "Brain Copy constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];	
}

Brain &Brain::operator=(const Brain &copy){
	std::cout << "Brain Copy assignment operator called\n";
	if (this != &copy){
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}

std::string	Brain::get_ideas(unsigned int index){
	return _ideas[index];
}

void	Brain::set_ideas(std::string ideas, unsigned int index){
	if (index >= 0 && index <= 99)	
		_ideas[index] = ideas;
}
