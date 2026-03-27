/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:16:46 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 01:34:44 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK_HPP
#define __PHONE_BOOK_HPP 1

#include "Contact.hpp"

class PhoneBook
{
private:
	int	_next_idx;
	int _count;
	Contact _contacts[8];

	// Displays contact entries
	void display() const;
	// Continues to try to save the field until it's not empty
	static std::string readField(const std::string& msg);
	// Helper to truncate to 10 chars for display
	static std::string truncate(const std::string& str);

public:
	PhoneBook();
	
	void addContact();
	void search() const;

	// Remove trailing and leading whitespace
	static std::string trim(const std::string& str);
	
	~PhoneBook();
};

#endif