/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:17:49 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:21:52 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "(Brain) Default ctor called" << std::endl;
	for (size_t i = 0; i < 100; ++i) {
		ideas[i] = "Zzzz... A fly flies around...";
	}
}

Brain::Brain(Brain const& src) {
	std::cout << "(Brain) Copy ctor called" << std::endl;
	for (size_t i = 0; i < 100; ++i) {
		ideas[i] = src.ideas[i];
	}
}

Brain& Brain::operator=(Brain const& src) {
	std::cout << "(Brain) Assignment called" << std::endl;
	for (size_t i = 0; i < 100; ++i) {
		ideas[i] = src.ideas[i];
	}
	return *this;
}

// 0-indexed
void Brain::setIdeaAt(size_t index, std::string const& idea) {
	if(index >= 100) {
		std::cout << "Index out of bounds" << std::endl; 
		return;
	}
	ideas[index] = idea;
}

// 0-indexed
std::string Brain::getIdeaAt(size_t index) const {
	if(index >= 100) {
		std::cout << "Index out of bounds" << std::endl; 
		return "";
	}
	return ideas[index];
}

Brain::~Brain() {
	std::cout << "(Brain) Default dctor called" << std::endl;
}
