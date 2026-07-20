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

#include "ScavTrap.hpp"
/*
Creating characters:
You start by making three robots: Hikaru (ClapTrap), Umi (ScavTrap), and
clone (ScavTrap without a name). Later, you also create Fuu as a ScavTrap
but store it in a ClapTrap pointer.

Copying stats:
clone is assigned the same stats as Umi.
Fuu is created with its own stats and stored in a pointer.

Actions begin:
Hikaru attacks Umi, takes damage, repairs itself, and eventually loses
all health after heavy damage. Hikaru tries to attack and repair again,
but fails once health is gone.

Umi attacks Fuu several times, repairs itself repeatedly, and uses its
special guardGate ability. After taking a huge amount of damage, Umi
tries to attack and repair again, but fails once health is gone.

Fuu (through the pointer) attacks Hikaru multiple times, repairs itself,
and also uses guardGate by casting back to ScavTrap. After taking heavy
damage, Fuu eventually loses health and can no longer act. Finally,
the pointer is deleted, which calls the destructor to clean up.

End of the story:
Each action prints out what happened — whether the attack worked,
whether the repair succeeded, or whether the robot was already “dead.”
By the end, you can see how health and energy values change as the
robots fight, heal, and wear out.
*/
int	main(void)
{
	ClapTrap	Hikaru("Hikaru");
	ScavTrap	Umi("Umi");
	ScavTrap	clone;
	ClapTrap	*Fuu_ptr;

	clone = ScavTrap(Umi);
	Fuu_ptr = new ScavTrap("Fuu");
	Hikaru.attack("Umi");
	Hikaru.takeDamage(0);
	Hikaru.beRepaired(10);
	Hikaru.takeDamage(25);
	Hikaru.attack("Fuu");
	Hikaru.beRepaired(35);
	Hikaru.takeDamage(55);

	for (int i = 0; i < 25; i++)
		Umi.attack("Fuu");
	Umi.takeDamage(0);
	for (int i = 0; i < 25; i++)
		Umi.beRepaired(15);
	Umi.guardGate();
	Umi.takeDamage(250);
	Umi.attack("Hikaru");
	Umi.beRepaired(35);
	Umi.takeDamage(55);
	Umi.guardGate();
	Umi.takeDamage(170);
	Umi.attack("Hikaru");
	Umi.beRepaired(35);
	Umi.takeDamage(55);
	Umi.guardGate();

	for (int i = 0; i < 25; i++)
		Fuu_ptr->attack("Hikaru");
	Fuu_ptr->takeDamage(0);
	for (int i = 0; i < 25; i++)
		Fuu_ptr->beRepaired(10);
	dynamic_cast<ScavTrap*>(Fuu_ptr)->guardGate();
	Fuu_ptr->takeDamage(175);
	Fuu_ptr->attack("Umi");
	Fuu_ptr->beRepaired(66);
	Fuu_ptr->takeDamage(77);
	dynamic_cast<ScavTrap*>(Fuu_ptr)->guardGate();
	Fuu_ptr->takeDamage(98);
	Fuu_ptr->attack("Umi");
	Fuu_ptr->beRepaired(66);
	Fuu_ptr->takeDamage(77);
	dynamic_cast<ScavTrap*>(Fuu_ptr)->guardGate();
	delete Fuu_ptr;
	return (0);
}
