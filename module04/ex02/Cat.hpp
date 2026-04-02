/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:51:33 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:34:23 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP 1

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public AAnimal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(std::string type);
	Cat(Cat const& src);

	Cat& operator=(Cat const& src);

	void setIdeaAt(size_t index, std::string idea);
	std::string getIdeaAt(size_t index) const;

	virtual void makeSound() const;

	~Cat();
};

#endif