/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:16:41 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/25 23:20:12 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& fn, const std::string& ln, const std::string& nn, 
		const std::string& pn, const std::string& ds)
	: _first_name(fn), _last_name(ln), _nickname(nn), _phone_number(pn), _darkest_secret(ds) {}


// Getters
std::string Contact::getFirstName()		const { return _first_name; }
std::string Contact::getLastName()		const { return _last_name; }
std::string Contact::getNickname()		const { return _nickname; }
std::string Contact::getPhoneNumber()	const { return _phone_number; }
std::string Contact::getDarkestSecret()	const { return _darkest_secret; }

// Setter
void Contact::setContact(const std::string& fn, const std::string& ln, const std::string& nn, 
	const std::string& pn, const std::string& ds)
	{
		_first_name = fn;
    	_last_name = ln;
		_nickname = nn;
		_phone_number = pn;
		_darkest_secret = ds;
	}

Contact::~Contact() {}
