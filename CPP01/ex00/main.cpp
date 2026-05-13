#include "Zombie.hpp"
# include <iostream>
# include <string>

static const char* MSG_COLOR = "\033[36m"; // cyan
static const char* MSG_RESET = "\033[0m";

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
		std::cout << MSG_COLOR << "--------------------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "CONTRUCTORS WITHOUT ARGUMENTS" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "--------------------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "This is a zombie class without arguments to demonstrate constructor override:" << MSG_RESET << std::endl;
	Zombie	no_arg;
	no_arg.announce();
		std::cout << MSG_COLOR << "\n---------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "CONTRUCTORS WITH ARGUMENTS" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "---------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "Creating a stack zombie named Crawler using randomChump:" << MSG_RESET << std::endl;
	randomChump("Crawler");
		std::cout << MSG_COLOR << "Its lifespan is within the scope of the function." << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "---------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "Creating a heap zombie named Walker using newZombie as it returns a new pointer:" << MSG_RESET << std::endl;
	Zombie*	zombie_heap = newZombie("Walker");
	std::cout << std::endl;
		std::cout << MSG_COLOR << "It remains in memory and could be used throughout the program until we delete it." << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "Like Walker's announcement is called in the main:" << MSG_RESET << std::endl;
	zombie_heap->announce();
	std::cout << std::endl;
		std::cout << MSG_COLOR << "Now we will delete Walker and free the memory allocated for it." << MSG_RESET << std::endl;
	delete zombie_heap;
		std::cout << MSG_COLOR << "If it wasn't deleted, it would remain immortal in the heap causing a memory leak.\n" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "--------------------------------------------------------------------------------------------" << MSG_RESET << std::endl;
		std::cout << MSG_COLOR << "no_arg's zombie is destroyed at the end of the main function as it is where it was declared." << MSG_RESET << std::endl;
}
