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
#include "DiamondTrap.hpp"

static void	printStats(const std::string& label, const DiamondTrap& diamond)
{
	std::cout << label << ": ClapTrap name=" << diamond.getName()
		<< ", hit points=" << diamond.getHitPoints()
		<< ", energy points=" << diamond.getEnergyPoints()
		<< ", attack damage=" << diamond.getAttackDamage() << std::endl;
}

static void	checkSharedClapTrap(DiamondTrap& diamond)
{
	ClapTrap	*fromScav = static_cast<ScavTrap*>(&diamond);
	ClapTrap	*fromFrag = static_cast<FragTrap*>(&diamond);

	std::cout << "Exactly one ClapTrap base: "
		<< (fromScav == fromFrag ? "yes" : "no") << std::endl;
}

int	main(void)
{
	std::cout << "=== Named construction ===" << std::endl;
	DiamondTrap	robot("Robot");
	robot.whoAmI();
	printStats("initial", robot);
	checkSharedClapTrap(robot);
	robot.attack("target");
	robot.guardGate();
	robot.highFivesGuys();
	printStats("after attack", robot);

	std::cout << "\n=== Copy construction ===" << std::endl;
	DiamondTrap	copy(robot);
	copy.whoAmI();
	printStats("copy", copy);

	std::cout << "\n=== Default construction and copy assignment ===" << std::endl;
	DiamondTrap	assigned;
	assigned.whoAmI();
	printStats("default", assigned);
	assigned = robot;
	assigned.whoAmI();
	printStats("assigned", assigned);

	std::cout << "\n=== Destruction in reverse construction order ==="
		<< std::endl;
	return (0);
}
