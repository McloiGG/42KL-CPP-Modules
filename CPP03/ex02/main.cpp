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

#include "FragTrap.hpp"
/*
Creating characters:
You start by making three robots: Amu (ClapTrap), Ran (FragTrap), and
clone (FragTrap without a name). Later, you also create Miki as a FragTrap
but store it in a ClapTrap pointer.

Copying stats:
clone is assigned the same stats as Ran.
Miki is created with its own stats and stored in a pointer.

Actions begin:
Amu attacks Ran, takes damage, repairs itself, and eventually loses
all health after heavy damage. Amu tries to attack and repair again,
but fails once health is gone.

Ran attacks Miki several times, repairs itself repeatedly, and uses its
special guardGate ability. After taking a huge amount of damage, Ran
tries to attack and repair again, but fails once health is gone.

Miki (through the pointer) attacks Amu multiple times, repairs itself,
and also uses guardGate by casting back to FragTrap. After taking heavy
damage, Miki eventually loses health and can no longer act. Finally,
the pointer is deleted, which calls the destructor to clean up.

End of the story:
Each action prints out what happened — whether the attack worked,
whether the repair succeeded, or whether the robot was already “dead.”
By the end, you can see how health and energy values change as the
robots fight, heal, and wear out.
*/
int	main(void)
{
	ClapTrap	Amu("Amu");
	FragTrap	Ran("Ran");
	FragTrap	clone;
	ClapTrap	*Miki_ptr;

	clone = FragTrap(Ran);
	Miki_ptr = new FragTrap("Miki");
	Amu.attack("Ran");
	Amu.takeDamage(0);
	Amu.beRepaired(10);
	Amu.takeDamage(25);
	Amu.attack("Miki");
	Amu.beRepaired(35);
	Amu.takeDamage(55);

	for (int i = 0; i < 50; i++)
		Ran.attack("Miki");
	Ran.takeDamage(0);
	for (int i = 0; i < 50; i++)
		Ran.beRepaired(15);
	Ran.highFivesGuys();
	Ran.takeDamage(500);
	Ran.attack("Amu");
	Ran.beRepaired(35);
	Ran.takeDamage(55);
	Ran.highFivesGuys();
	Ran.takeDamage(295);
	Ran.attack("Amu");
	Ran.beRepaired(35);
	Ran.takeDamage(55);
	Ran.highFivesGuys();

	for (int i = 0; i < 50; i++)
		Miki_ptr->attack("Amu");
	Miki_ptr->takeDamage(0);
	for (int i = 0; i < 50; i++)
		Miki_ptr->beRepaired(10);
	dynamic_cast<FragTrap*>(Miki_ptr)->highFivesGuys();
	Miki_ptr->takeDamage(300);
	Miki_ptr->attack("Ran");
	Miki_ptr->beRepaired(66);
	Miki_ptr->takeDamage(77);
	dynamic_cast<FragTrap*>(Miki_ptr)->highFivesGuys();
	Miki_ptr->takeDamage(223);
	Miki_ptr->attack("Ran");
	Miki_ptr->beRepaired(66);
	Miki_ptr->takeDamage(77);
	dynamic_cast<FragTrap*>(Miki_ptr)->highFivesGuys();
	delete Miki_ptr;
	return (0);
}
