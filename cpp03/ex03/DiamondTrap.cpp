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
	ClapTrap::_name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy){
	std::cout << "DiamondTrap Copy constructor called\n";
	_name = copy._name;
	_hitPoints = copy._damage;
	_energyPoints = copy._energyPoints;
	_damage = copy._damage;
	 ClapTrap::_name = _name + "_clap_name";

}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &copy){
		_name = copy._name;
		_hitPoints = copy._damage;
		_energyPoints = copy._energyPoints;
		_damage = copy._damage;
		ClapTrap::_name = _name + "_clap_name";
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
