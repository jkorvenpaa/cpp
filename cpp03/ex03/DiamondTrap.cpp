#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
   std::cout << "DiamondTrap Default constructor called\n";
   	_name = "";
	FragTrap tmp;
	_hitPoints = tmp.getHitp();
	_energyPoints = ScavTrap::_energyPoints;
	_damage = tmp.getDamage();
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor called\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"){
	std::cout << "DiamondTrap constructor called\n";
	FragTrap tmp;
	_name = name;
	_hitPoints = tmp.getHitp();
	_energyPoints = ScavTrap::_energyPoints;
	_damage = tmp.getDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy){
	std::cout << "DiamondTrap Copy constructor called\n";
	_name = copy._name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_damage = FragTrap::_damage;

}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &copy){
		ClapTrap(copy._name + "_clap_name");
		_name = copy._name;
		_hitPoints = FragTrap::_hitPoints;
		_energyPoints = ScavTrap::_energyPoints;
		_damage = FragTrap::_damage;
	}
	return *this;

}

void DiamondTrap::whoAmI(){
	
	std::cout << GREY << "I am DiamondTrap "<< _name  << " from ClapTrap " << ClapTrap::_name
	<< std::endl << RESET;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
