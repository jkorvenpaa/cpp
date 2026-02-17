#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << " FragTrap Default constructor called\n";
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "ScavTrap Constructor called\n";
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
	std::cout << "ScavTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
	std::cout << "ScavTrap Copy assignment operator called\n";
	_name = copy._name;
	_hitPoints = copy._hitPoints; 
	_energyPoints = copy._energyPoints;
	_damage = copy._damage;
	return *this;
}


void	FragTrap::highFivesGuys(void){
	std::cout << BLUE << "High five FragTrap " << _name <<  "!!!!!" << std::endl << RESET;
}