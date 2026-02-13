#pragma once
#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_damage;
	
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


