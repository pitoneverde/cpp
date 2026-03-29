/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:12:09 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:41:06 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP
#define __CLAPTRAP_HPP 1

#include <string>
#include <iostream>
#include <climits>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

protected:
	ClapTrap();	//protected constructor to keep canonical form

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	
	ClapTrap& operator=(ClapTrap const& src);

	// getters
	std::string& getName();
	unsigned int& getHitPoints();
	unsigned int& getEnergyPoints();
	unsigned int& getAttackDamage();
	void setName(std::string const& value);
	void setHitPoints(unsigned int const& value);
	void setEnergyPoints(unsigned int const& value);
	void setAttackDamage(unsigned int const& value);

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

	~ClapTrap();
};

#endif