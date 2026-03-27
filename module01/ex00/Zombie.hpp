/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:57 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 18:48:57 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP
#define __ZOMBIE_HPP 1

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string const &n);

	// prints message <name>: BraiiiiiiinnnzzzZ..
	void announce();

	// stackalloc
	static void randomChump(std::string name);
	// malloc
	static Zombie* newZombie(std::string name);

	~Zombie();
};

#endif