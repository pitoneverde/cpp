/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:26 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:56:12 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP
#define __HUMANB_HPP 1

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string _name;
	Weapon*	_weapon;

public:
	HumanB(std::string n);

	// because it can be null
	Weapon* getWeapon() const;
	void setWeapon(Weapon& w);
	
	void attack();
	~HumanB();
};

#endif