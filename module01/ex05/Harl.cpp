/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:15:09 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 15:58:11 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout <<  "I think I deserve to have some extra bacon for free. I've been coming for \
years, whereas you started working here just last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	// Anon struct followed by a static const map of levels and pointers to private member functions
	static const struct {
		std::string level;
		void (Harl::*f)();
	} map[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	// Not a forest of if-else, just an array lookup
	// Or did the subject expect an hashing function?
	for (size_t i = 0; i < sizeof(map)/sizeof(map[0]); ++i) {
		if (level == map[i].level) {
			(this->*map[i].f)();
			return;
		}
	}
}

Harl::~Harl() {}
