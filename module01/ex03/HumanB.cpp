/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:30 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:59:11 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : _name(n), _weapon(NULL) {}

Weapon* HumanB::getWeapon() const { return _weapon; }

// Can do this safely because a reference is always non-null
void HumanB::setWeapon(Weapon& w) { _weapon = &w; }

void HumanB::attack() {
	if (_weapon == NULL) {
		std::cout << _name << " attacks with their bare hands" << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

HumanB::~HumanB() {}