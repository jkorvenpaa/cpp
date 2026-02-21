#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name(""),_hitPoints(0), _energyPoints(0), _damage(0){
	std::cout << "ClapTrap Default constructor called\n"; 
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called\n";
}

ClapTrap::ClapTrap(std::string name): _hitPoints(10), _energyPoints(10), _damage(10){
	_name = name;
	std::cout << "ClapTrap Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	_name = copy._name;
	std::cout << "ClapTrap Copy constructor called\n";
}
	
ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	if (this != &copy){
		std::cout << "ClapTrap Copy assignment operator called\n";
		_name = copy._name;
		_hitPoints = copy._hitPoints; 
		_energyPoints = copy._energyPoints;
		_damage = copy._damage;
	}
	return *this;
}

//When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
//Attack costs 1 energy point.
void ClapTrap::attack(const std::string& target){
	if (_energyPoints == 0){
		std::cout << VIOLET << _name << " has no energy points to attack\n" << RESET;
		return ;
	}
	_energyPoints --; 
	std::cout << GREEN << "**ClapTrap " << _name << " attacks " << target <<
	" causing " << _damage << " points of damage!**\n";
	std::cout << "Energy points = " << _energyPoints << std::endl << RESET;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints == 0){
		std::cout << VIOLET << _name << " is dead (no hit points left to take more damage)\n" << RESET;
		return ;
	}
	if (_hitPoints >= amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	std::cout << RED << "**ClapTrap " << _name << " takes damage " << amount << " points!**\n";
	std::cout << "Hit points = " << _hitPoints << std::endl << RESET;
}

//When ClapTrap repairs itself, it regains <amount> hit points.
//Repair costs 1 energy point.
void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints == 0){
		std::cout << VIOLET << _name << " is dead (no hit points left to repair)\n" << RESET;
		return ;
	}
	if (_energyPoints == 0){
		std::cout << VIOLET << _name << " has no energy points for repair\n" << RESET;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;

	std::cout << YELLOW << "**ClapTrap " << _name << " repairs with " << amount << " points**\n";
	std::cout << "Energy points = " << _energyPoints << std::endl;
	std::cout << "Hit points = " << _hitPoints << std::endl << RESET;

}