#include "ClapTrap.hpp"

int	main(void){
	ClapTrap clapA("Harry");
	ClapTrap clapB("Voldemort");

	//clapA = clapB;
	clapA.attack("DeathEater");
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