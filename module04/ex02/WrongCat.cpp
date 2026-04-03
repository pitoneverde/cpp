/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:30 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:42 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "(WrongCat) Default ctor called" << std::endl;
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "(WrongCat) String ctor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) {
	std::cout << "(WrongCat) Copy ctor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& src) {
	type = src.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat hisses at you!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "(WrongCat) Default dctor called" << std::endl;
}