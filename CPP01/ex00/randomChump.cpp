#include "Zombie.hpp"
# include <string>

void	randomChump(std::string name)
{
	Zombie	newZombie(name);
	newZombie.announce();
}
