/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:19:52 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 18:53:05 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// alloc'ed with new
	Zombie* z = Zombie::newZombie("Foo");
	z->announce();
	
	// stackalloc'ed
	Zombie::randomChump("Bar");
	
	delete z;
	return 0;
}
