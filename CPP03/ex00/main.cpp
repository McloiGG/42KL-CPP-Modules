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
#include "ClapTrap.hpp"

static void	printState(const std::string& label, const ClapTrap& trap)
{
	std::cout << label << ": name=" << trap.getName()
		<< ", hit points=" << trap.getHitPoints()
		<< ", energy points=" << trap.getEnergyPoints()
		<< ", attack damage=" << trap.getAttackDamage() << std::endl;
}

int	main(void)
{
	std::cout << "=== Construction and basic actions ===" << std::endl;
	ClapTrap	unit("Unit");
	printState("initial", unit);
	unit.attack("target");
	unit.takeDamage(4);
	unit.beRepaired(3);
	printState("after attack, damage, and repair", unit);

	std::cout << "\n=== Copy construction and assignment ===" << std::endl;
	ClapTrap	copy(unit);
	ClapTrap	assigned;
	printState("default", assigned);
	assigned = unit;
	printState("copy", copy);
	printState("assigned", assigned);

	std::cout << "\n=== No-energy boundary ===" << std::endl;
	unit.setEnergyPoints(1);
	unit.attack("target");
	unit.attack("target");
	unit.beRepaired(1);
	printState("exhausted", unit);

	std::cout << "\n=== Lethal-damage boundary ===" << std::endl;
	ClapTrap	fallen("Fallen");
	fallen.takeDamage(100);
	fallen.attack("target");
	fallen.beRepaired(1);
	printState("fallen", fallen);

	std::cout << "\n=== Destruction ===" << std::endl;
	return (0);
}
