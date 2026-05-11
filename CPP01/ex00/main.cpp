#include "Zombie.hpp"
# include <iostream>
# include <string>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "CONTRUCTORS WITH ARGUMENTS" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "This is a zombie class without arguments to demonstrate constructor override:" << std::endl;
	Zombie	no_arg;
	no_arg.announce();
	std::cout << "\n---------------------------------------------------------------------------------" << std::endl;
	std::cout << "CONTRUCTORS WITHOUT ARGUMENTS" << std::endl;
	std::cout << "---------------------------------------------------------------------------------" << std::endl;
	std::cout << "Creating a stack zombie named Crawler using randomChump:" << std::endl;
	randomChump("Crawler");
	std::cout << "It's lifespan is within the scope of the function." << std::endl;
	std::cout << "---------------------------------------------------------------------------------" << std::endl;
	std::cout << "Creating a heap zombie named Walker using newZombie as it returns a new pointer:" << std::endl;
	Zombie*	zombie_heap = newZombie("Walker");
	std::cout << std::endl;
	std::cout << "It remains in memory and could be used throughout the program until we delete it." << std::endl;
	std::cout << "Like Walker's announcement is called in the main:" << std::endl;
	zombie_heap->announce();
	std::cout << std::endl;
	std::cout << "Now we will delete Walker and free the memory allocated for it." << std::endl;
	delete zombie_heap;
	std::cout << "If it wasn't deleted, it would remain immortal in the heap causing a memory leak.\n" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "no_arg's zombie is destroyed at the end of the main function as it is where it was declared." << std::endl;
}
