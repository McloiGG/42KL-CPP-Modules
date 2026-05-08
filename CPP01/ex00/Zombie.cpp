#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed Zombie")
{
	std::cout << "A zombie has appeared!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " has been infected!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has decayed and withered away..." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
