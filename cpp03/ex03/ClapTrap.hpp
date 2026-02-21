#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[92m"
#define RED     "\033[91m"
#define YELLOW  "\033[93m"
#define VIOLET  "\033[95m"

class ClapTrap
{
protected:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_damage;
	
public:
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


