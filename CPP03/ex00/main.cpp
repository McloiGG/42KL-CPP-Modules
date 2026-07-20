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

#include "ClapTrap.hpp"
/*
Creating characters:
You start by making several ClapTrap robots:
Blossom_shadow, Blossom, Blossom_clone, Bubbles, and Buttercup.
Some are made with names, some without, and one is a copy of another.

Copying stats:
Blossom_shadow takes on Blossom’s stats,
and Buttercup is reassigned to a new ClapTrap named “Buttercup.”

Actions begin:
Blossom attacks Bubbles (0 damage).
Blossom take damage (5 amount).
Blossom recover health (100 amount).

Bubbles attacks Buttercup (0 damage and repeat 5 times).
Bubbles recover health (15 amount and repeat 5 times).
Bubbles attacks Buttercup (failed due to zero energy).
Bubbles recover health (failed due to zero energy).
Bubbles take damage (50 amount).

Buttercup attacks Blossom (0 damage).
Buttercup take damage (0 amount for testing string output).
Buttercup recover health (10 amount).
Buttercup take damage (died due to damage exceed health).
Buttercup attacks Bubbles (failed due to zero health).
Buttercup recover health (failed due to zero health).

End of the story:
Each action prints out what happened whether the attack worked,
whether the repair succeeded, or whether the robot was already “dead.”

By the end, you can see how the health and energy values change
as the robots fight, heal, and wear out.
*/
int	main(void)
{
	ClapTrap	Blossom_shadow;
	ClapTrap	Blossom("Blossom");
	ClapTrap	Blossom_clone(Blossom);
	ClapTrap	Bubbles("Bubbles");
	ClapTrap	Buttercup;

	Blossom_shadow = Blossom;
	Buttercup = ClapTrap("Buttercup");
	Blossom.attack("Bubbles");
	Blossom.takeDamage(5);
	Blossom.beRepaired(100);
	Blossom.takeDamage(0);

	Bubbles.attack("Buttercup");
	Bubbles.attack("Buttercup");
	Bubbles.attack("Buttercup");
	Bubbles.attack("Buttercup");
	Bubbles.attack("Buttercup");
	Bubbles.beRepaired(15);
	Bubbles.beRepaired(15);
	Bubbles.beRepaired(15);
	Bubbles.beRepaired(15);
	Bubbles.beRepaired(15);
	Bubbles.attack("Buttercup");
	Bubbles.beRepaired(15);
	Bubbles.takeDamage(50);
	Bubbles.takeDamage(0);
	
	Buttercup.attack("Blossom");
	Buttercup.takeDamage(0);
	Buttercup.beRepaired(10);
	Buttercup.takeDamage(25);
	Buttercup.attack("Bubbles");
	Buttercup.beRepaired(35);
	Buttercup.takeDamage(55);
	return (0);
}
