#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed with default values." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

std::string ClapTrap::setName(std::string newName)
{
	name = newName;
	return name;
}

int ClapTrap::setHitPoints(int newHitPoints)
{
	hitPoints = newHitPoints;
	return hitPoints;
}

int ClapTrap::setEnergyPoints(int newEnergyPoints)
{
	energyPoints = newEnergyPoints;
	return energyPoints;
}

int ClapTrap::setAttackDamage(int newAttackDamage)
{
	attackDamage = newAttackDamage;
	return attackDamage;
}

bool ClapTrap::isAlive() const
{
	if (hitPoints > 0)
		return true;
	std::cout << "ClapTrap " << name << " is dead." << std::endl;
	return false;
}

bool ClapTrap::consumeEnergy()
{
	if (energyPoints > 0)
	{
		energyPoints--;
		return true;
	}
	std::cout << "ClapTrap " << name << " has no energy left." << std::endl;
	return false;
}

void	ClapTrap::attack(const std::string& target)
{
	if (isAlive() && consumeEnergy())
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " cannot attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (isAlive())
	{
		hitPoints -= amount;
		if (hitPoints < 0) hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
		isAlive();
	} else
		std::cout << "ClapTrap " << name << " cannot take more damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isAlive() && consumeEnergy())
	{
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! New hit points: " << hitPoints << std::endl;
	} else
		std::cout << "ClapTrap " << name << " cannot be repaired." << std::endl;
}
