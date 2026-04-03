/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:38 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:34:16 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP 1

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public AAnimal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(std::string type);
	Dog(Dog const& src);

	Dog& operator=(Dog const& src);

	void setIdeaAt(size_t index, std::string idea);
	std::string getIdeaAt(size_t index) const;

	virtual void makeSound() const;

	~Dog();
};

#endif