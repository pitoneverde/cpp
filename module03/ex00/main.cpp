/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:15 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 19:42:50 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap("trap1");

	// trap.setAttackDamage(10);
	trap.attack("goblin");

	trap.takeDamage(5);
	trap.beRepaired(3);

	trap.takeDamage(8);
	// died, nothing happens
	trap.attack("goblin");
	trap.beRepaired(10);
	trap.takeDamage(2);
	return 0;
}
