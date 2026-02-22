#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << " FragTrap Default constructor called\n";
	_name = "";
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "FragTrap Constructor called\n";
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
	std::cout << "FragTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
	std::cout << "FragTrap Copy assignment operator called\n";
	if (this != &copy){
		_name = copy._name;
		_hitPoints = copy._hitPoints; 
		_energyPoints = copy._energyPoints;
		_damage = copy._damage;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << LBLUE << "High five FragTrap " << _name <<  "!!!!!" << std::endl << RESET;
}
