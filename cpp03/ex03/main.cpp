#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){

	DiamondTrap da("Riddle");
	DiamondTrap db("Marvolo");
	DiamondTrap dc(da);
	db = da;
	da.whoAmI();
	db.whoAmI();
	dc.whoAmI();
	da.attack("Slytherin");
	db.attack("Slytherin");
	dc.attack("Slytherin");

	// da.takeDamage(10);
	// da.attack("Slytherin");
	// da.beRepaired(10);
	// da.highFivesGuys();
	// da.guardGate();
	// da.whoAmI();
	// da.takeDamage(10);
	// da.attack("Slytherin");
	// da.beRepaired(10);
	// da.highFivesGuys();
	// da.guardGate();
	return 0;
}