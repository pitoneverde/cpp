/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:50:15 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 23:12:30 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "(FragTrap) Default ctor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	std::cout << "(FragTrap) Copy ctor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "(FragTrap) String ctor called" << std::endl;
	setAttackDamage(30);
	setEnergyPoints(100);
	setHitPoints(100);
}

// Implicitly casted to ClapTrap, uses parent's assignment operator
FragTrap& FragTrap::operator=(FragTrap const& src) {
	std::cout << "(FragTrap) assignment operator called" << std::endl;
	ClapTrap copy = static_cast<ClapTrap>(src);
	setName(copy.getName());
	setAttackDamage(copy.getAttackDamage());
	setEnergyPoints(copy.getEnergyPoints());
	setHitPoints(copy.getHitPoints());
	return *this;
}

// Overrides to change messages:
void FragTrap::attack(const std::string& target) {
	if (getHitPoints() == 0 || getEnergyPoints() == 0) return;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!" << std::endl;
}

// void FragTrap::takeDamage(unsigned int amount) {

// }

// void FragTrap::beRepaired(unsigned int amount) {
	
// }
void FragTrap::highFiveGuys() {
	if (getHitPoints() == 0 || getEnergyPoints() == 0) return;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " is giving high fives!" << std::endl;
}


FragTrap::~FragTrap() {
	std::cout << "(FragTrap) Default dctor called" << std::endl;
}