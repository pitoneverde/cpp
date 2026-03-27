/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:24 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:28:46 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const& t) : _type(t) {}

std::string const& Weapon::getType() const { return _type; }

void Weapon::setType(std::string const& t) { _type = t; }

Weapon::~Weapon() {}