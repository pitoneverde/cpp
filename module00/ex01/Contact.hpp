/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:16:37 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/25 23:16:57 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP
#define __CONTACT_HPP 1

#include <string>

class Contact
{
	private:
	std::string _first_name;
	std::string _last_name;
	std::string	_nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	public:
	Contact();
	Contact(const std::string& fn, const std::string& ln, const std::string& nn, 
		const std::string& pn, const std::string& ds);
	
	// Getters
    std::string getFirstName()		const;
    std::string getLastName()		const;
    std::string getNickname()		const;
    std::string getPhoneNumber()	const;
    std::string getDarkestSecret()	const;
    
    // Setter
    void setContact(const std::string& fn, const std::string& ln, const std::string& nn, 
		const std::string& pn, const std::string& ds);
	
	~Contact();
};

#endif