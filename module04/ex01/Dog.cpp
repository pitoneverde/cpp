/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:35 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:01:32 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "(Dog) Default ctor called" << std::endl;
	brain = new Brain();
}
Dog::Dog(std::string type) : Animal(type) {
	std::cout << "(Dog) String ctor called" << std::endl;
	brain = new Brain();
}
Dog::Dog(Dog const& src) : Animal(src) {
	std::cout << "(Dog) Copy ctor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(Dog const& src) {
	type = src.type;
	brain = new Brain(*src.brain);
	return *this;
}

void Dog::setIdeaAt(size_t index, std::string idea) { brain->setIdeaAt(index, idea); }
std::string Dog::getIdeaAt(size_t index) const { return brain->getIdeaAt(index); }

void Dog::makeSound() const {
	std::cout << "Dog barks at you!" << std::endl;
}

Dog::~Dog() {
	std::cout << "(Dog) Default dctor called" << std::endl;
	delete brain;
}