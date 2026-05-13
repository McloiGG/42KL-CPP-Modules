#include "Zombie.hpp"
# include <iostream>

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

void Zombie::setName( std::string name )
{
	this->_name = name;
	std::cout << "The zombie is now named " << this->_name << std::endl;
}
