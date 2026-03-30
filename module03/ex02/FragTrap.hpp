/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:50:17 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:53:58 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP
#define __FRAGTRAP_HPP 1

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();
public:
	FragTrap(FragTrap const& src);
	FragTrap(std::string name);

	FragTrap& operator=(FragTrap const& src);
	
	void attack(const std::string& target);
	// virtual void takeDamage(unsigned int amount);
	// virtual void beRepaired(unsigned int amount);
	void highFiveGuys();

	~FragTrap();
};

#endif