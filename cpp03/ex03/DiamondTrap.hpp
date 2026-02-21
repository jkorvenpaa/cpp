#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define GREY "\033[90m"


class DiamondTrap: virtual public FragTrap , virtual public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
	DiamondTrap(std::string name);

	void attack(const std::string &target);
	void whoAmI();
};