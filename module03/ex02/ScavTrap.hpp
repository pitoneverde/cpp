/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:53:26 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 21:44:26 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP
#define __SCAVTRAP_HPP 1

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();
public:
	ScavTrap(ScavTrap const& src);
	ScavTrap(std::string name);

	ScavTrap& operator=(ScavTrap const& src);
	
	void attack(const std::string& target);
	// virtual void takeDamage(unsigned int amount);
	// virtual void beRepaired(unsigned int amount);
	void guardGate();

	~ScavTrap();
};

#endif