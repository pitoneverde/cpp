/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:33 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:58:15 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP
#define __HUMANA_HPP 1

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string _name;
	Weapon&	_weapon;

public:
	HumanA(std::string n, Weapon& w);

	Weapon& getWeapon() const;
	void setWeapon(Weapon& w);
	
	void attack();
	~HumanA();
};

#endif