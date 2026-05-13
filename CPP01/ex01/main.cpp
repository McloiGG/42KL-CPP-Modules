#include "Zombie.hpp"
# include <iostream>
# include <string>

static const char* MSG_COLOR = "\033[36m"; // cyan
static const char* MSG_RESET = "\033[0m";

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	std::cout << MSG_COLOR << "The new[] operator allocates memory for an array of objects in a single allocation." << MSG_RESET << std::endl;
	std::cout << MSG_COLOR << "\nN Zombie objects are allocated at once using zombieHorde:" << MSG_RESET << std::endl;
	Zombie*	horde = zombieHorde(5, "Horde");
	std::cout << MSG_COLOR << "\nEach zombie in the horde can announce itself ( horde[i] ):" << MSG_RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << MSG_COLOR << "Zombie " << i + 1 << ": " << MSG_RESET;
		horde[i].announce();
	}
	std::cout << MSG_COLOR << "\nThe delete[] operator deallocates memory and calls destructors for an array of objects created with new[]:" << MSG_RESET << std::endl;
	delete[] horde;
	std::cout << MSG_COLOR << "\nUsing delete/delete[] on a pointer returned by the non-matching new operator will cause undefined behavior." << MSG_RESET << std::endl;
}
