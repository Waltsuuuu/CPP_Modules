#include "Zombie.hpp"
#include <iostream>

int	main() {
	int N = 11;

	Zombie *horde = zombieHorde(N, "ZOOMBI");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}