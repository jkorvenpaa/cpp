#include "Zombie.hpp"


int	main(){

	Zombie* zombie;

	zombie = newZombie("Heap");
	randomChump("Stack");
	delete(zombie);
	return (0);

}