#pragma once
#include "ClapTrap.hpp"

#define BLUE "\033[94m"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	void guardGate();
	void attack(const std::string& target);

};


