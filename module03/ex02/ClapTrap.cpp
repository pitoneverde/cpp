/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:12 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:27:30 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "(ClapTrap) Default ctor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << "(ClapTrap) String ctor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
	std::cout << "(ClapTrap) Copy ctor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& src) {
	std::cout << "(ScavTrap) assignment operator called" << std::endl;
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return *this;
}

std::string ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
void ClapTrap::setName(std::string const& value) { _name = value; }
void ClapTrap::setHitPoints(unsigned int const& value) { _hitPoints = value; }
void ClapTrap::setEnergyPoints(unsigned int const& value) { _energyPoints = value; }
void ClapTrap::setAttackDamage(unsigned int const& value) { _attackDamage = value; }

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0 || _energyPoints == 0) return;
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// Underflow protection
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0 || _energyPoints == 0) return;
	// --_energyPoints;
	(amount >= _hitPoints) ? _hitPoints = 0 : _hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " is attacked, taking " << amount << " points of damage!" << std::endl;
}

// Overflow protection
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0 || _energyPoints == 0) return;
	--_energyPoints;
	(amount > UINT_MAX - _hitPoints) ? _hitPoints = UINT_MAX : _hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}


ClapTrap::~ClapTrap() {
	std::cout << "(ClapTrap) Default dctor called" << std::endl;
}