#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap Default constructor called\n";
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "ScavTrap Constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
	std::cout << "ScavTrap Copy constructor called\n";
	_name = copy._name;
	_hitPoints = copy._hitPoints; 
	_energyPoints = copy._energyPoints;
	_damage = copy._damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){

	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &copy){
		_name = copy._name;
		_hitPoints = copy._hitPoints; 
		_energyPoints = copy._energyPoints;
		_damage = copy._damage;
	}
	return *this;
}

void ScavTrap::guardGate(){
 std::cout << BLUE << _name << " ScavTrap is now in Gate keeper mode\n" << RESET;
}

void ScavTrap::attack(const std::string& target){
	if (_energyPoints == 0){
		std::cout << VIOLET << _name << " has no energy points to attack\n" << RESET;
		return ;
	}
	_energyPoints --; 
	std::cout << GREEN << "**ScavTrap " << _name << " attacks " << target <<
	" causing " << _damage << " points of damage!**\n";
	std::cout << "Energy points = " << _energyPoints << std::endl << RESET;
}