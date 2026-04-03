/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:27 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:05 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "(AAnimal) Default ctor called" << std::endl;
}
AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "(AAnimal) String ctor called" << std::endl;
}
AAnimal::AAnimal(AAnimal const& src) {
	std::cout << "(AAnimal) Copy ctor called" << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(AAnimal const& src) {
	type = src.type;
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal makes sound" << std::endl;
}

std::string AAnimal::getType() const { return type; }
void AAnimal::setType(std::string const& value) { type = value; }

AAnimal::~AAnimal() {
	std::cout << "(AAnimal) Default dctor called" << std::endl;
}