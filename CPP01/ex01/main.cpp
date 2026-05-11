#include "Zombie.hpp"
# include <iostream>
# include <string>

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	std::cout << "The new[] operator allocates memory for an array of objects in a single allocation." << std::endl;
	std::cout << "\nN Zombie objects are allocated at once using zombieHorde:" << std::endl;
	Zombie*	horde = zombieHorde(5, "Horde");
	std::cout << "\nEach zombie in the horde can announce itself ( horde[i] ):" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		horde[i].announce();
	}
	std::cout << "\nThe delete[] operator deallocates memory and calls destructors for an array of objects created with new[]:" << std::endl;
	delete[] horde;
	std::cout << "\nUsing delete/delete[] on a pointer returned by the non-matching new operator will cause undefined behavior." << std::endl;
}
