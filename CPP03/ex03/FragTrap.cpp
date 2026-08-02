#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap("Default FragTrap", FRAG_HIT_POINTS,
		FRAG_ENERGY_POINTS, FRAG_ATTACK_DAMAGE)
{
	std::cout << "FragTrap " << getName() << " constructed with default values." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, FRAG_HIT_POINTS, FRAG_ENERGY_POINTS, FRAG_ATTACK_DAMAGE)
{
	std::cout << "FragTrap " << getName() << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << getName() << " copy constructed." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << getName() << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " destructed." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " gives a high five!" << std::endl;
}
