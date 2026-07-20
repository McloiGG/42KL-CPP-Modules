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
/*
Creating characters:
You start by making three robots: Nezuko (ClapTrap), Shinobu (DiamondTrap), and
clone (DiamondTrap without a name). Later, you also create Mitsuri as a
DiamondTrap but store it in a ClapTrap pointer.

Copying stats:
clone is assigned the same stats as Shinobu.
Mitsuri is created with its own stats and stored in a pointer.

Actions begin:
Nezuko attacks Shinobu, takes damage, repairs itself, and eventually loses
all health after heavy damage. Nezuko tries to attack and repair again,
but fails once health is gone.

Shinobu attacks Mitsuri several times, repairs itself repeatedly, and uses its
special whoAmI ability. After taking a huge amount of damage, Shinobu
tries to attack and repair again, but fails once health is gone.

Mitsuri (through the pointer) attacks Nezuko multiple times, repairs itself,
and also uses whoAmI by casting back to DiamondTrap. After taking heavy
damage, Mitsuri eventually loses health and can no longer act. Finally,
the pointer is deleted, which calls the destructor to clean up.

End of the story:
Each action prints out what happened — whether the attack worked,
whether the repair succeeded, or whether the robot was already “dead.”
By the end, you can see how health and energy values change as the
robots fight, heal, and wear out.
*/
int	main(void)
{
	ClapTrap	Nezuko("Nezuko");
	DiamondTrap	Shinobu("Shinobu");
	DiamondTrap	clone;
	ClapTrap	*Mitsuri_ptr;

	clone = DiamondTrap(Shinobu);
	Mitsuri_ptr = new DiamondTrap("Mitsuri");
	Nezuko.attack("Shinobu");
	Nezuko.takeDamage(0);
	Nezuko.beRepaired(10);
	Nezuko.takeDamage(25);
	Nezuko.attack("Mitsuri");
	Nezuko.beRepaired(35);
	Nezuko.takeDamage(55);

	for (int i = 0; i < 25; i++)
		Shinobu.attack("Mitsuri");
	Shinobu.takeDamage(0);
	for (int i = 0; i < 25; i++)
		Shinobu.beRepaired(15);
	Shinobu.guardGate();
	Shinobu.highFivesGuys();
	Shinobu.whoAmI();
	Shinobu.takeDamage(350);
	Shinobu.attack("Nezuko");
	Shinobu.beRepaired(35);
	Shinobu.takeDamage(55);
	Shinobu.guardGate();
	Shinobu.highFivesGuys();
	Shinobu.whoAmI();
	Shinobu.takeDamage(295);
	Shinobu.attack("Nezuko");
	Shinobu.beRepaired(35);
	Shinobu.takeDamage(55);
	Shinobu.guardGate();
	Shinobu.highFivesGuys();
	Shinobu.whoAmI();

	for (int i = 0; i < 25; i++)
		Mitsuri_ptr->attack("Nezuko");
	Mitsuri_ptr->takeDamage(0);
	for (int i = 0; i < 25; i++)
		Mitsuri_ptr->beRepaired(10);
	dynamic_cast<ScavTrap*>(Mitsuri_ptr)->guardGate();
	dynamic_cast<FragTrap*>(Mitsuri_ptr)->highFivesGuys();
	dynamic_cast<DiamondTrap*>(Mitsuri_ptr)->whoAmI();
	Mitsuri_ptr->takeDamage(200);
	Mitsuri_ptr->attack("Shinobu");
	Mitsuri_ptr->beRepaired(66);
	Mitsuri_ptr->takeDamage(77);
	dynamic_cast<ScavTrap*>(Mitsuri_ptr)->guardGate();
	dynamic_cast<FragTrap*>(Mitsuri_ptr)->highFivesGuys();
	dynamic_cast<DiamondTrap*>(Mitsuri_ptr)->whoAmI();
	Mitsuri_ptr->takeDamage(100);
	Mitsuri_ptr->attack("Shinobu");
	Mitsuri_ptr->beRepaired(66);
	Mitsuri_ptr->takeDamage(77);
	dynamic_cast<ScavTrap*>(Mitsuri_ptr)->guardGate();
	dynamic_cast<FragTrap*>(Mitsuri_ptr)->highFivesGuys();
	dynamic_cast<DiamondTrap*>(Mitsuri_ptr)->whoAmI();
	delete Mitsuri_ptr;
	return (0);
}
