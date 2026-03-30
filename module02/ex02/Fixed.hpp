/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:01:41 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 22:01:32 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP
#define __FIXED_HPP 1

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_rawBits;
	static const int _precision = 8;
public:
	// ctors
	Fixed();
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const& src);

	// operators
	Fixed& operator=(Fixed const& rhs);

	bool operator>(Fixed const& rhs) const;
	bool operator<(Fixed const& rhs) const;
	bool operator<=(Fixed const& rhs) const;
	bool operator>=(Fixed const& rhs) const;
	bool operator==(Fixed const& rhs) const;
	bool operator!=(Fixed const& rhs) const;

	Fixed operator+(Fixed const& rhs) const;
	Fixed operator-(Fixed const& rhs) const;
	Fixed operator*(Fixed const& rhs) const;
	Fixed operator/(Fixed const& rhs) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	// getters
	int getRawBits() const;
	void setRawBits(int const raw);

	// conversions
	float toFloat() const;
	int toInt() const;

	// minmax
	static Fixed min(Fixed& a, Fixed& b);
	static Fixed min(Fixed const& a, Fixed const& b);
	static Fixed max(Fixed& a, Fixed& b);
	static Fixed max(Fixed const& a, Fixed const& b);

	// dctors
	~Fixed();
};

std::ostream& operator<<(std::ostream& o, Fixed const& f);

#endif