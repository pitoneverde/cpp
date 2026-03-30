/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:23 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 22:02:26 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Ctors

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
	// _rawBits = src._rawBits;
}

// Operators

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = rhs._rawBits;
	return *this;
}

bool Fixed::operator>(Fixed const& rhs) const {
    return _rawBits > rhs._rawBits;
}

bool Fixed::operator<(Fixed const& rhs) const {
    return _rawBits < rhs._rawBits;
}

bool Fixed::operator<=(Fixed const& rhs) const {
    return _rawBits <= rhs._rawBits;
}

bool Fixed::operator>=(Fixed const& rhs) const {
    return _rawBits >= rhs._rawBits;
}

bool Fixed::operator==(Fixed const& rhs) const {
    return _rawBits == rhs._rawBits;
}

bool Fixed::operator!=(Fixed const& rhs) const {
    return _rawBits != rhs._rawBits;
}

Fixed Fixed::operator+(Fixed const& rhs) const {
	Fixed res;
	res.setRawBits(_rawBits + rhs._rawBits);
	return res;
}

Fixed Fixed::operator-(Fixed const& rhs) const {
	Fixed res;
	res.setRawBits(_rawBits - rhs._rawBits);
	return res;
}

Fixed Fixed::operator*(Fixed const& rhs) const {
	Fixed res;
	long long raw = static_cast<long long>(_rawBits) * rhs._rawBits;
	raw >>= _precision;		// equivalent to division by 2^precision
	res.setRawBits(static_cast<int>(raw));
	return res;
}

Fixed Fixed::operator/(Fixed const& rhs) const {
	Fixed res;
	// multiply by 2^precision before division
	long long raw = static_cast<long long>(_rawBits) << _precision;
	raw /= rhs._rawBits;
	res.setRawBits(static_cast<int>(raw));
	return res;
}

Fixed& Fixed::operator++() {
	// Increment must add 1 to rawBits (the smallest epsilon in Fixed)
	_rawBits += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

// Getters

int Fixed::getRawBits() const {
	// std::cout << "getRawBits() memf called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits() memf called" << std::endl;
	_rawBits = raw;
}

// Conversions

float Fixed::toFloat() const {
	// equivalent to division by 2^_precision, but more efficient
	return static_cast<float>(_rawBits) / (1 << _precision);
}

int Fixed::toInt() const {
	return _rawBits >> _precision;
}

// Minmax
Fixed Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

Fixed Fixed::min(Fixed const& a, Fixed const& b) {
    return (a < b) ? a : b;
}

Fixed Fixed::max(Fixed const& a, Fixed const& b) {
    return (a > b) ? a : b;
}

// Dctor

Fixed::~Fixed() {
	std::cout << "Default dctor called" << std::endl;
}


std::ostream& operator<<(std::ostream& o, Fixed const& f)
{
	o << f.toFloat();
	return o;
}