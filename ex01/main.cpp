#include "Zombie.hpp"
#include <iostream>

int main(void) {
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	
	std::cout << "=== Zombie Horde Announcing ===" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\n=== Deleting Horde ===" << std::endl;
	delete[] horde;
	
	return 0;
}
