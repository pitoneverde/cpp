/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:27 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:05 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "(WrongAnimal) Default ctor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "(WrongAnimal) String ctor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const& src) {
	std::cout << "(WrongAnimal) Copy ctor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& src) {
	type = src.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }
void WrongAnimal::setType(std::string const& value) { type = value; }

WrongAnimal::~WrongAnimal() {
	std::cout << "(WrongAnimal) Default dctor called" << std::endl;
}