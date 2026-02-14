#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name(""),_hitPoints(0), _energyPoints(0), _damage(0){
	std::cout << "Default constructor called\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(std::string name): _hitPoints(10), _energyPoints(10), _damage(10){
	_name = name;
	std::cout << "Constructor called\n";
}
/*
ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy constructor called\n";
}
	
ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout << "Copy assignment operator called\n";
	return *this;
}*/

//When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
//Attack costs 1 energy point.
void ClapTrap::attack(const std::string& target){

	if (_energyPoints == 0){
		std::cout << _name << " has no energy points to attack\n";
		return ;
	}
	_energyPoints -= 1; 
	std::cout << "ClapTrap " << _name << " attacks " << target <<
	" causing " << _damage << " points of damage!\n";
	std::cout << "ClapTrap " << _name << ": energy points = " << _energyPoints << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints >= amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << ": hit points = " << _hitPoints << std::endl;
}

//When ClapTrap repairs itself, it regains <amount> hit points.
//Repair costs 1 energy point.
void ClapTrap::beRepaired(unsigned int amount){
	
	if (_energyPoints == 0 || _hitPoints == 0){
		std::cout << _name << " has no energy/hit points for repair\n";
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1; 

	std::cout << "ClapTrap " << _name << " repairs with " << amount << " points\n";
	std::cout << "ClapTrap " << _name << ": energy points = " << _energyPoints << std::endl;
	std::cout << "ClapTrap " << _name << ": hit points = " << _hitPoints << std::endl;

}