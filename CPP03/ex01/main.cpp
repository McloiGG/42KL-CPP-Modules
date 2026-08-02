/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiew <ktiew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:29:07 by ktiew             #+#    #+#             */
/*   Updated: 2026/02/22 00:05:09 by ktiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

static void	printState(const std::string& label, const ClapTrap& trap)
{
	std::cout << label << ": name=" << trap.getName()
		<< ", hit points=" << trap.getHitPoints()
		<< ", energy points=" << trap.getEnergyPoints()
		<< ", attack damage=" << trap.getAttackDamage() << std::endl;
}

int	main(void)
{
	std::cout << "=== ScavTrap construction and abilities ===" << std::endl;
	ScavTrap	unit("Scav");
	printState("initial", unit);
	unit.attack("target");
	unit.guardGate();
	printState("after attack", unit);

	std::cout << "\n=== Copy construction and assignment ===" << std::endl;
	ScavTrap	copy(unit);
	ScavTrap	assigned;
	printState("default", assigned);
	assigned = unit;
	printState("copy", copy);
	printState("assigned", assigned);

	std::cout << "\n=== ScavTrap no-energy boundary ===" << std::endl;
	assigned.setEnergyPoints(0);
	assigned.attack("target");
	printState("exhausted", assigned);

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}
