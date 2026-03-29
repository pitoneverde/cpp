/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:09 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 19:38:22 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP
#define __CLAPTRAP_HPP 1

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	ClapTrap();	//private constructor to keep canonical form

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	
	ClapTrap& operator=(ClapTrap const& src);

	// getters
	unsigned int& getHitPoints();
	unsigned int& getEnergyPoints();
	unsigned int& getAttackDamage();
	void setHitPoints(unsigned int const& value);
	void setEnergyPoints(unsigned int const& value);
	void setAttackDamage(unsigned int const& value);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	~ClapTrap();
};

#endif