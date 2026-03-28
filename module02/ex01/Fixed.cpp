/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:23 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 21:20:27 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default ctor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int ctor called" << std::endl;
	_rawBits = n << _precision;
}

Fixed::Fixed(float const n) {
	std::cout << "Float ctor called" << std::endl;
	_rawBits = static_cast<int>(roundf(n * (1 << _precision)));
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy ctor called" << std::endl;
	*this = src;
	// _rawBits = src.getRawBits();
}


Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = rhs.getRawBits();
	return *this;
}


int Fixed::getRawBits() const {
	// std::cout << "getRawBits() memf called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits() memf called" << std::endl;
	_rawBits = raw;
}

float Fixed::toFloat() const {
	// equivalent to division by 2^_precision, but more efficient
	return static_cast<float>(_rawBits) / (1 << _precision);
}

int Fixed::toInt() const {
	return _rawBits >> _precision;
}


Fixed::~Fixed() {
	std::cout << "Default dctor called" << std::endl;
}


std::ostream& operator<<(std::ostream& o, Fixed const& f)
{
	o << f.toFloat();
	return o;
}