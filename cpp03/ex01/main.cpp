#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	ClapTrap clapA("Harry");
	//ClapTrap clapB("Voldemort");

	ScavTrap scavA("Fluffy");
	ScavTrap scavB("Nagini");

	//clapA = clapB;
	clapA.attack("Dementor");
/*	for (int i = 0; i < 9; i++)
		clapB.attack("Witch");
	clapB.takeDamage(6);
	clapB.beRepaired(10);
	clapA.takeDamage(20);
	clapB.takeDamage(20);
	clapA.takeDamage(5);
	clapB.beRepaired(10);
*/
	scavA = scavB;
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
	
	return 0;
	
}