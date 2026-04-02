/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:01:29 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:20:44 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP 1

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain const& src);
	
	Brain& operator=(Brain const& src);

	void setIdeaAt(size_t index, std::string const& idea);
	std::string getIdeaAt(size_t index) const;

	~Brain();
};

#endif