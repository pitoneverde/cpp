/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:48:22 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/27 00:28:41 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP
#define __WEAPON_HPP 1

#include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string const& t);

	std::string const& getType() const;
	void setType(std::string const& t);

	~Weapon();
};

#endif