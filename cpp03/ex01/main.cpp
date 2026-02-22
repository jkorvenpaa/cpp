#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){


	ScavTrap scavA("Fluffy");
	ScavTrap scavB("Nagini");

	// ScavTrap scavC(scavB);
	// scavA = scavB;
	// scavA.guardGate();
	// scavB.guardGate();
	// scavC.guardGate();

	scavA.attack("DeathEater");
	for (int i = 0; i < 9; i++)
		scavB.attack("Wizard");
	scavB.takeDamage(6);
	scavB.beRepaired(10);
	scavA.takeDamage(20);
	scavB.takeDamage(110);
	scavA.takeDamage(5);
	scavA.guardGate();
	scavB.beRepaired(10);

	// ClapTrap clapA("Harry");
	// ClapTrap clapB("Voldemort");
	
	// ClapTrap clapC(clapB);
	// clapA = clapB;
	// clapC.beRepaired(10);
	// clapA.beRepaired(10);
	// clapB.beRepaired(10);
	
	// clapA.attack("Dementor");
	// for (int i = 0; i < 9; i++)
	// 	clapB.attack("Witch");
	// clapB.takeDamage(6);
	// clapB.beRepaired(10);
	// clapA.takeDamage(20);
	// clapB.takeDamage(20);
	// clapA.takeDamage(5);
	// clapB.beRepaired(10);
	

	
	return 0;
	
}