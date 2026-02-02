#include "Zombie.hpp"


int	main(){
	int N = 7;

	if (N > 0){
		Zombie* horde = zombieHorde(N, "zzzzzzz");
		delete[] horde;
	}
	return (0);
}