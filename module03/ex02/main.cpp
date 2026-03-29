/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:15 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 23:09:28 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== FragTrap Construction (showing inherited stats) ===" << std::endl;
	FragTrap frag("FR4G-TP");
	
	// Verify FragTrap has different initial stats (100 HP / 100 Energy / 30 Attack)
	std::cout << "Name: " << frag.getName() << std::endl;
	std::cout << "HP: " << frag.getHitPoints() << " (expected: 100)" << std::endl;
	std::cout << "Energy: " << frag.getEnergyPoints() << " (expected: 100)" << std::endl;
	std::cout << "Attack: " << frag.getAttackDamage() << " (expected: 30)" << std::endl;
	
	std::cout << "\n=== FragTrap Specific Attack ===" << std::endl;
	frag.attack("Skag");  // Should show FragTrap-specific message and use 30 damage
	
	std::cout << "\n=== High Five Guys (FragTrap unique) ===" << std::endl;
	frag.highFiveGuys();
	
	std::cout << "\n=== Inherited Methods ===" << std::endl;
	frag.takeDamage(50);    // Inherited from ClapTrap
	std::cout << "HP after damage: " << frag.getHitPoints() << std::endl;
	
	frag.beRepaired(25);    // Inherited from ClapTrap
	std::cout << "HP after repair: " << frag.getHitPoints() << std::endl;
	std::cout << "Energy after repair: " << frag.getEnergyPoints() << std::endl;
	
	std::cout << "\n=== Copy Construction ===" << std::endl;
	FragTrap fragCopy(frag);
	std::cout << "Copy Name: " << fragCopy.getName() << std::endl;
	fragCopy.attack("Target Dummy");
	
	std::cout << "\n=== Assignment Operator ===" << std::endl;
	FragTrap fragAssign("Temporary");
	fragAssign = frag;
	std::cout << "Assigned Name: " << fragAssign.getName() << std::endl;
	fragAssign.highFiveGuys();
	
	std::cout << "\n=== Energy Depletion (FragTrap has 100) ===" << std::endl;
	FragTrap tired("TiredBot");
	tired.setEnergyPoints(1);  // Set to 1 to test exhaustion quickly
	tired.attack("Air");       // Uses energy
	std::cout << "Energy: " << tired.getEnergyPoints() << std::endl;
	tired.attack("Air");       // Should fail (no energy)
	tired.beRepaired(5);       // Should fail (no energy)
	tired.highFiveGuys();      // Test if high five costs energy (usually doesn't, but check)
	
	std::cout << "\n=== Death Behavior ===" << std::endl;
	FragTrap dead("DeadBot");
	dead.takeDamage(200);      // Overkill damage
	std::cout << "HP: " << dead.getHitPoints() << std::endl;
	dead.attack("Ghost");      // Should fail (dead)
	dead.highFiveGuys();       // Should fail or work? (usually fails if dead)
	
	std::cout << "\n=== Destruction Order Test ===" << std::endl;
	{
		FragTrap temp("Temp");
		std::cout << "Temp created" << std::endl;
		// Both ClapTrap and FragTrap destructors should be called here
	}
	
	std::cout << "\n=== Full Combat Sequence ===" << std::endl;
	FragTrap fighter("Champion");
	fighter.attack("Boss");
	fighter.attack("Boss");
	fighter.takeDamage(40);
	fighter.beRepaired(20);
	fighter.highFiveGuys();
	std::cout << "Final stats - HP: " << fighter.getHitPoints() 
			  << ", Energy: " << fighter.getEnergyPoints() << std::endl;
	
	return 0;
}