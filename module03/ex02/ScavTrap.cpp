/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 20:06:34 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:42:33 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "(ScavTrap) Default ctor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
	std::cout << "(ScavTrap) Copy ctor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "(ScavTrap) String ctor called" << std::endl;
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
}

// Implicitly casted to ClapTrap, uses parent's assignment operator
ScavTrap& ScavTrap::operator=(ScavTrap const& src) {
	std::cout << "(ScavTrap) assignment operator called" << std::endl;
	ClapTrap copy = static_cast<ClapTrap>(src);
	setName(copy.getName());
	setAttackDamage(copy.getAttackDamage());
	setEnergyPoints(copy.getEnergyPoints());
	setHitPoints(copy.getHitPoints());
	return *this;
}

// Overrides to change messages:
void ScavTrap::attack(const std::string& target) {
	if (getHitPoints() == 0 || getEnergyPoints() == 0) return;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
}

// void ScavTrap::takeDamage(unsigned int amount) {

// }

// void ScavTrap::beRepaired(unsigned int amount) {
	
// }

void ScavTrap::guardGate() {
	if (getHitPoints() == 0 || getEnergyPoints() == 0) return;
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "(ScavTrap) Default dctor called" << std::endl;
}