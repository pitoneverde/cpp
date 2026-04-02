/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:27 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:05 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "(Animal) Default ctor called" << std::endl;
}
Animal::Animal(std::string type) : type(type) {
	std::cout << "(Animal) String ctor called" << std::endl;
}
Animal::Animal(Animal const& src) {
	std::cout << "(Animal) Copy ctor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(Animal const& src) {
	type = src.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const { return type; }
void Animal::setType(std::string const& value) { type = value; }

Animal::~Animal() {
	std::cout << "(Animal) Default dctor called" << std::endl;
}