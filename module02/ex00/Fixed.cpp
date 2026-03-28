/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:23 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 19:37:57 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default ctor called" << std::endl;
}
Fixed::Fixed(Fixed& src) {
	std::cout << "Copy ctor called" << std::endl;
	_rawBits = src.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Default dctor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	_rawBits = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits() memf called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits() memf called" << std::endl;
	_rawBits = raw;
}