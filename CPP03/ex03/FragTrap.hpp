#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	enum
	{
		FRAG_HIT_POINTS = 100,
		FRAG_ENERGY_POINTS = 100,
		FRAG_ATTACK_DAMAGE = 30
	};

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);
	~FragTrap();

	void	highFivesGuys();
};

#endif
