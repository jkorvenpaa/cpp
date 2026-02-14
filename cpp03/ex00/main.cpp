#include "ClapTrap.hpp"

int	main(void){
	ClapTrap clapA("Harry");
	ClapTrap clapB("Voldemort");

	clapA.attack("DeathEater");
	clapB.attack("Witch");
	clapA.takeDamage(5);
	clapB.takeDamage(20);
	clapA.takeDamage(5);
	clapB.beRepaired(10);
	//clapA = clapB;
	return 0;
	
}