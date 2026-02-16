#pragma once
#include "ClapTrap.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[92m"
#define RED     "\033[91m"
#define YELLOW  "\033[93m"
#define VIOLET   "\033[95m"

class ScavTrap : public ScavTrap
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


