/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:35 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:38:23 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "(Dog) Default ctor called" << std::endl;
}
Dog::Dog(std::string type) : Animal(type) {
	std::cout << "(Dog) String ctor called" << std::endl;
}
Dog::Dog(Dog const& src) : Animal(src) {
	std::cout << "(Dog) Copy ctor called" << std::endl;
}

Dog& Dog::operator=(Dog const& src) {
	type = src.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog barks at you!" << std::endl;
}

Dog::~Dog() {
	std::cout << "(Dog) Default dctor called" << std::endl;
}