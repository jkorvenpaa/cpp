#include "ClapTrap.hpp"

int	main(void){
	ClapTrap clapA("Harry");
	ClapTrap clapB("Voldemort");
	
	// ClapTrap clapC(clapB);
	// clapA = clapB;
	// clapC.beRepaired(10);
	// clapA.beRepaired(10);
	// clapB.beRepaired(10);
	
	clapA.attack("Dementor");
	for (int i = 0; i < 9; i++)
		clapB.attack("Witch");
	clapB.takeDamage(6);
	clapB.beRepaired(10);
	clapA.takeDamage(20);
	clapB.takeDamage(20);
	clapA.takeDamage(5);
	clapB.beRepaired(10);
	
	return 0;
	
}