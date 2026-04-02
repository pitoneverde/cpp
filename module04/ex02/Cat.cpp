/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:30 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:35:23 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "(Cat) Default ctor called" << std::endl;
	brain = new Brain();
}
Cat::Cat(std::string type) : AAnimal(type) {
	std::cout << "(Cat) String ctor called" << std::endl;
	brain = new Brain();
}
Cat::Cat(Cat const& src) : AAnimal(src) {
	std::cout << "(Cat) Copy ctor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(Cat const& src) {
	type = src.type;
	brain = new Brain(*src.brain);
	return *this;
}

void Cat::setIdeaAt(size_t index, std::string idea) { brain->setIdeaAt(index, idea); }
std::string Cat::getIdeaAt(size_t index) const { return brain->getIdeaAt(index); }

void Cat::makeSound() const {
	std::cout << "Cat hisses at you!" << std::endl;
}

Cat::~Cat() {
	std::cout << "(Cat) Default dctor called" << std::endl;
	delete brain;
}