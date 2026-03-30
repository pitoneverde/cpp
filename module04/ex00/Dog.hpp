/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:38 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:55 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP
#define __DOG_HPP 1

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string type);
	Dog(Dog const& src);

	Dog& operator=(Dog const& src);

	virtual void makeSound() const;

	~Dog();
};

#endif