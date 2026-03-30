/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:15 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:57:43 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ClapTrap Construction (default stats) ===" << std::endl;
	ClapTrap trap("trap1");
	
	// Verify initial ClapTrap stats
	std::cout << "Name: " << trap.getName() << std::endl;
	std::cout << "HP: " << trap.getHitPoints() << " (expected: 10)" << std::endl;
	std::cout << "Energy: " << trap.getEnergyPoints() << " (expected: 10)" << std::endl;
	std::cout << "Attack: " << trap.getAttackDamage() << " (expected: 0)" << std::endl;
	
	std::cout << "\n=== Attack (default 0 damage) ===" << std::endl;
	trap.attack("goblin");  // Should attack but deal 0 damage or require setting damage first
	
	std::cout << "\n=== Setting Attack Damage ===" << std::endl;
	trap.setAttackDamage(5);
	std::cout << "Attack damage set to: " << trap.getAttackDamage() << std::endl;
	trap.attack("goblin");  // Now deals 5 damage
	
	std::cout << "\n=== Taking Damage ===" << std::endl;
	trap.takeDamage(5);
	std::cout << "HP after taking 5 damage: " << trap.getHitPoints() << " (expected: 5)" << std::endl;
	std::cout << "Energy after taking damage: " << trap.getEnergyPoints() << std::endl;  // Should cost energy?
	
	std::cout << "\n=== Repairing ===" << std::endl;
	trap.beRepaired(3);
	std::cout << "HP after repairing 3: " << trap.getHitPoints() << " (expected: 8)" << std::endl;
	std::cout << "Energy after repair: " << trap.getEnergyPoints() << std::endl;  // Should be 8 (if both cost 1)
	
	std::cout << "\n=== Death Sequence ===" << std::endl;
	trap.takeDamage(8);  // Takes 8 damage, HP was 8, should go to 0
	std::cout << "HP after lethal damage: " << trap.getHitPoints() << " (expected: 0)" << std::endl;
	
	// Try actions while dead
	std::cout << "Attempting actions while dead/destroyed:" << std::endl;
	trap.attack("ghost");      // Should fail (dead)
	trap.beRepaired(10);       // Should fail (dead)
	trap.takeDamage(2);        // Should fail (already dead)
	
	std::cout << "\n=== Copy Construction ===" << std::endl;
	ClapTrap trapCopy(trap);
	std::cout << "Copy Name: " << trapCopy.getName() << std::endl;
	std::cout << "Copy HP: " << trapCopy.getHitPoints() << std::endl;
	trapCopy.setAttackDamage(3);
	trapCopy.attack("target");
	
	std::cout << "\n=== Assignment Operator ===" << std::endl;
	ClapTrap trapAssign("Temporary");
	trapAssign = trap;
	std::cout << "Assigned Name: " << trapAssign.getName() << std::endl;
	std::cout << "Assigned HP: " << trapAssign.getHitPoints() << std::endl;
	
	std::cout << "\n=== Energy Depletion (ClapTrap has 10) ===" << std::endl;
	ClapTrap tired("TiredBot");
	tired.setAttackDamage(1);
	
	// Attack 10 times to deplete energy
	for (int i = 0; i < 10; i++) {
		tired.attack("training_dummy");
	}
	std::cout << "Energy after 10 attacks: " << tired.getEnergyPoints() << " (expected: 0)" << std::endl;
	
	std::cout << "Attempting actions with no energy:" << std::endl;
	tired.attack("air");       // Should fail (no energy)
	tired.beRepaired(5);       // Should fail (no energy)
	
	std::cout << "\n=== Destruction Order ===" << std::endl;
	{
		ClapTrap temp("Temp");
		std::cout << "Temp created" << std::endl;
		// Destructor should be called here
	}
	
	return 0;
}