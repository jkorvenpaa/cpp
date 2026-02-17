#pragma once
#include "ClapTrap.hpp"

#define BLUE "\033[94m"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	~FragTrap();
	FragTrap(std:: string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	void highFivesGuys(void);
};
