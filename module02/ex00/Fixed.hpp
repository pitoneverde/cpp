/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:01:41 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 19:37:08 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP
#define __FIXED_HPP 1

#include <iostream>

class Fixed
{
private:
	int	_rawBits;
	static const int _precision = 8;
public:
	Fixed();
	Fixed(Fixed& src);
	Fixed& operator=(Fixed const& rhs);
	
	int getRawBits() const;
	void setRawBits(int const raw);

	~Fixed();
};

#endif