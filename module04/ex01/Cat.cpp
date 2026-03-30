/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:30 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:42 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "(Cat) Default ctor called" << std::endl;
}
Cat::Cat(std::string type) : Animal(type) {
	std::cout << "(Cat) String ctor called" << std::endl;
}
Cat::Cat(Cat const& src) : Animal(src) {
	std::cout << "(Cat) Copy ctor called" << std::endl;
}

Cat& Cat::operator=(Cat const& src) {
	type = src.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat hisses at you!" << std::endl;
}

Cat::~Cat() {
	std::cout << "(Cat) Default dctor called" << std::endl;
}