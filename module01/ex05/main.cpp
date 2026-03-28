/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:12:37 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 15:58:45 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "Testing DEBUG..." << std::endl;
	harl.complain("DEBUG");

	std::cout << "Testing INFO..." << std::endl;
	harl.complain("INFO");

	std::cout << "Testing WARNING..." << std::endl;
	harl.complain("WARNING");

	std::cout << "Testing ERROR..." << std::endl;
	harl.complain("ERROR");

	std::cout << "Testing INVALID... (nothing should be printed)" << std::endl;
	harl.complain("INVALID");

	return 0;
}
