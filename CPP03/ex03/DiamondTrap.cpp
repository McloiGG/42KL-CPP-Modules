#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name", FragTrap::FRAG_HIT_POINTS,
		ScavTrap::SCAV_ENERGY_POINTS, FragTrap::FRAG_ATTACK_DAMAGE),
	ScavTrap(), FragTrap(), name("Default")
{
	std::cout << "DiamondTrap " << this->name
		<< " constructed with default values." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& newName)
	: ClapTrap(newName + "_clap_name", FragTrap::FRAG_HIT_POINTS,
		ScavTrap::SCAV_ENERGY_POINTS, FragTrap::FRAG_ATTACK_DAMAGE),
	ScavTrap(newName), FragTrap(newName), name(newName)
{
	std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << this->name
		<< " copy constructed." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << this->name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name
		<< ", ClapTrap name: " << ClapTrap::name << std::endl;
}
