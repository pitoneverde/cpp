/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:21 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 01:34:48 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main() {
	PhoneBook pb;
	std::string command;

	std::cout << "Welcome to the Awesome Phonebook!" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command);
		command = PhoneBook::trim(command);
		
		// convert command to uppercase
	 	for (std::string::size_type i = 0; i < command.size(); ++i) {
            command[i] = std::toupper(static_cast<unsigned char>(command[i]));
        }
		
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT") {
			std::cout << "Goodbye!\n";
			break;
		}
		else if (!command.empty())
			std::cout << "Invalid command. Try ADD, SEARCH, or EXIT." << std::endl;
	}

	return 0;
}
