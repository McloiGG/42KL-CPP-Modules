/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lming-ha <lming-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:29:07 by ktiew             #+#    #+#             */
/*   Updated: 2026/07/31 11:16:55 by lming-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	printState(const std::string& label, const ClapTrap& trap)
{
	std::cout << label << ": name=" << trap.getName()
		<< ", hit points=" << trap.getHitPoints()
		<< ", energy points=" << trap.getEnergyPoints()
		<< ", attack damage=" << trap.getAttackDamage() << std::endl;
}

int	main(void)
{
	std::cout << "=== FragTrap construction and ability ===" << std::endl;
	FragTrap	unit("Frag");
	printState("initial", unit);
	unit.attack("target");
	unit.takeDamage(40);
	unit.highFivesGuys();
	printState("after actions", unit);

	std::cout << "\n=== Copy construction and assignment ===" << std::endl;
	FragTrap	copy(unit);
	FragTrap	assigned;
	printState("default", assigned);
	assigned = unit;
	printState("copy", copy);
	printState("assigned", assigned);

	std::cout << "\n=== ScavTrap regression ===" << std::endl;
	ScavTrap	scav("Scav");
	printState("ScavTrap initial", scav);
	scav.attack("target");
	scav.guardGate();
	printState("ScavTrap after attack", scav);

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}
