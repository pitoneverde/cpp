/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:33 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 01:36:36 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP
#define __CAT_HPP 1

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string type);
	Cat(Cat const& src);

	Cat& operator=(Cat const& src);

	virtual void makeSound() const;

	~Cat();
};

#endif