#pragma once
#include "ClapTrap.hpp"

#define LBLUE "\033[96m"

class FragTrap : virtual public ClapTrap
{
private:

public:
	FragTrap();
	~FragTrap();
	FragTrap(std:: string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	void highFivesGuys(void);
	unsigned int getHitp();
	unsigned int getDamage();
};
