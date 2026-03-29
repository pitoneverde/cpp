/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:15 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:24:59 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ScavTrap Construction (showing inherited stats) ===" << std::endl;
	ScavTrap scav("SC4V-TP");
	
	// Verify ScavTrap has different initial stats than ClapTrap
	std::cout << "Name: " << scav.getName() << std::endl;
	std::cout << "HP: " << scav.getHitPoints() << " (expected: 100)" << std::endl;
	std::cout << "Energy: " << scav.getEnergyPoints() << " (expected: 50)" << std::endl;
	std::cout << "Attack: " << scav.getAttackDamage() << " (expected: 20)" << std::endl;
	
	std::cout << "\n=== ScavTrap Specific Attack ===" << std::endl;
	scav.attack("Bandit");  // Should show ScavTrap-specific message and use 20 damage
	
	std::cout << "\n=== Guard Gate (ScavTrap unique) ===" << std::endl;
	scav.guardGate();
	
	std::cout << "\n=== Inherited Methods ===" << std::endl;
	scav.takeDamage(30);    // Inherited from ClapTrap
	std::cout << "HP after damage: " << scav.getHitPoints() << std::endl;
	
	scav.beRepaired(15);    // Inherited from ClapTrap
	std::cout << "HP after repair: " << scav.getHitPoints() << std::endl;
	std::cout << "Energy after repair: " << scav.getEnergyPoints() << std::endl;
	
	std::cout << "\n=== Copy Construction ===" << std::endl;
	ScavTrap scavCopy(scav);
	std::cout << "Copy Name: " << scavCopy.getName() << std::endl;
	scavCopy.attack("Target Dummy");
	
	std::cout << "\n=== Assignment Operator ===" << std::endl;
	ScavTrap scavAssign("Temporary");
	scavAssign = scav;
	std::cout << "Assigned Name: " << scavAssign.getName() << std::endl;
	scavAssign.guardGate();
	
	std::cout << "\n=== Energy Depletion (ScavTrap has 50) ===" << std::endl;
	// Let's just show exhaustion:
	ScavTrap tired("TiredBot");
	tired.setEnergyPoints(1);  // Set to 1 to test exhaustion quickly
	tired.attack("Air");       // Uses energy
	std::cout << "Energy: " << tired.getEnergyPoints() << std::endl;
	tired.attack("Air");       // Should fail (no energy)
	tired.beRepaired(5);       // Should fail (no energy)
	
	std::cout << "\n=== Death Behavior ===" << std::endl;
	ScavTrap dead("DeadBot");
	dead.takeDamage(200);      // Overkill damage
	std::cout << "HP: " << dead.getHitPoints() << std::endl;
	dead.attack("Ghost");      // Should fail (dead)
	dead.guardGate();          // Should fail or work? (depends on implementation, usually fails if dead)
	
	std::cout << "\n=== Destruction Order Test ===" << std::endl;
	{
		ScavTrap temp("Temp");
		std::cout << "Temp created" << std::endl;
		// Both ClapTrap and ScavTrap destructors should be called here
	}	
	return 0;
}