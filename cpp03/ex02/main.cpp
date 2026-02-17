#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){




	ClapTrap clapA("Harry");
	ClapTrap clapB("Voldemort");
	//clapA = clapB;
	clapA.attack("Dementor");
	for (int i = 0; i < 9; i++)
		clapB.attack("Witch");
	clapB.takeDamage(6);
	clapB.beRepaired(10);
	clapA.takeDamage(20);
	clapB.takeDamage(20);
	//clapA.takeDamage(5);
	clapB.beRepaired(10);


	ScavTrap scavA("Fluffy");
	ScavTrap scavB("Nagini");
	//scavA = scavB;
	scavA.attack("DeathEater");
	for (int i = 0; i < 9; i++)
		scavB.attack("Wizard");
	scavB.takeDamage(6);
	scavB.beRepaired(10);
	scavA.takeDamage(20);
	scavB.takeDamage(110);
	//scavA.takeDamage(5);
	scavA.guardGate();
	scavB.guardGate();
	scavB.beRepaired(10);


	FragTrap FragA("Dobby");
	FragTrap FragB("Griphook");
	//trapA = trapB;
	FragA.attack("some Malfoy");
	for (int i = 0; i < 9; i++)
		FragB.attack("Dragon");
	FragB.takeDamage(6);
	FragB.beRepaired(10);
	FragA.takeDamage(20);
	FragB.takeDamage(110);
	//FragA.takeDamage(5);
	FragA.highFivesGuys();
	FragB.highFivesGuys();
	FragB.beRepaired(10);
	return 0;
	
}