/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:35 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:58:08 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon& w) : _name(n), _weapon(w) {}

Weapon& HumanA::getWeapon() const { return _weapon; }

void HumanA::setWeapon(Weapon& w) { _weapon = w; }

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {}