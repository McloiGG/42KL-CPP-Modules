#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	enum
	{
		SCAV_HIT_POINTS = 100,
		SCAV_ENERGY_POINTS = 50,
		SCAV_ATTACK_DAMAGE = 20
	};

public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator=(const ScavTrap& other);
	~ScavTrap();

	void			guardGate();
	virtual void	attack(const std::string& target);
};

#endif
