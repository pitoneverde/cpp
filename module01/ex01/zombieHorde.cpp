/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:56:42 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 19:07:02 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name) {
	Zombie* z = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		z[i].name = name;
	}
	return z;
}