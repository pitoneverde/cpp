/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:01:41 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 20:03:34 by sabruma          ###   ########.fr       */
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
	
	// getters
	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

	// dctors
	~Fixed();
};

std::ostream& operator<<(std::ostream& o, Fixed const& f);

#endif