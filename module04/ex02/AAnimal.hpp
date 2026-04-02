/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:12 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:33:48 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP 1

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(AAnimal const& src);

	AAnimal& operator=(AAnimal const& src);

	std::string getType() const;
	void setType(std::string const& value);

	virtual void makeSound() const = 0;

	// Apparently if i have to delete through base pointers 
	// i should define dctor as virtual
	virtual ~AAnimal();
};

#endif