/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:57 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 19:41:14 by sabruma          ###   ########.fr       */
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
	Zombie();
	Zombie(std::string const& n);

	// prints message <name>: BraiiiiiiinnnzzzZ..
	void announce();

	// stackalloc
	static void randomChump(std::string name);
	// malloc
	static Zombie* newZombie(std::string name);
	static Zombie* zombieHorde(int N, std::string name);
	~Zombie();
};

#endif