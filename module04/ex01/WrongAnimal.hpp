/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:12 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:21:01 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP 1

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const& src);

	WrongAnimal& operator=(WrongAnimal const& src);

	std::string getType() const;
	void setType(std::string const& value);

	void makeSound() const;

	// Apparently if i have to delete through base pointers 
	// i should define dctor as virtual
	virtual ~WrongAnimal();
};

#endif