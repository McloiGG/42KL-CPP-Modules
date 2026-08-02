#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;

	std::string	setName(std::string newName);
	int			setHitPoints(int newHitPoints);
	int			setEnergyPoints(int newEnergyPoints);
	int			setAttackDamage(int newAttackDamage);

	bool	isAlive() const;
	bool	consumeEnergy();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif