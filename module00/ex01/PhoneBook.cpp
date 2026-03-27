/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:16:43 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 01:35:54 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : _next_idx(0), _count(0) {}

void PhoneBook::display() const {
	std::cout << std::right;
	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First Name" << '|';
	std::cout << std::setw(10) << "Last Name" << '|';
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; ++i)
	{
		const Contact& c = 	_contacts[i];
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << truncate(c.getFirstName()) << '|';
		std::cout << std::setw(10) << truncate(c.getLastName()) << '|';
		std::cout << std::setw(10) << truncate(c.getNickname()) << std::endl;
	}
}

std::string	PhoneBook::readField(const std::string& msg) {
	std::string	field;
	do {
		std::cout << msg + ' ';
		std::getline(std::cin, field);
		field = trim(field);
		if (field.empty())
			std::cout << "Field cannot be empty. Please try again." << std::endl;
	} while (field.empty());
	return field;
}

std::string PhoneBook::truncate(const std::string& str) {
	if (str.length() <= 10)
		return str;
	else
		return str.substr(0, 9) + '.';
}



void PhoneBook::addContact() {
    std::string fn, ln, nn, pn, ds;

    std::cout << "Adding a new contact:" << std::endl;

	fn = readField("First name:");
	ln = readField("Last name:");
	nn = readField("Nickname:");
	pn = readField("Phone number:");
	ds = readField("Darkest secret:");

    _contacts[_next_idx] = Contact(fn, ln, nn, pn, ds);
    _next_idx = (_next_idx + 1) % 8;
    if (_count < 8)
        ++_count;

    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search() const {
	if (_count == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	display();
	
	// Let the user select the index
	int idx;
	std::cout << "Enter the index of the contact to display: " << std::endl;
	std::cin >> idx;
	if (std::cin.fail() || idx < 0 || idx >= _count) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// aka > LONG_MAX
		std::cout << "Invalid index." << std::endl;
	}
	std::cin.ignore();
	
	// Display details
	const Contact& c = _contacts[idx];
	std::cout << "First name:     " << c.getFirstName() << std::endl;
	std::cout << "Last name:      " << c.getLastName() << std::endl;
    std::cout << "Nickname:       " << c.getNickname() << std::endl;
    std::cout << "Phone number:   " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

std::string PhoneBook::trim(const std::string& str) {
    std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        return ""; // string is all whitespace

    std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}

PhoneBook::~PhoneBook() {}
