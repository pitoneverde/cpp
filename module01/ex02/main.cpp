/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:12:44 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 19:44:52 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;

	std::cout << "Address of s: " << &s << std::endl;
	std::cout << "Address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of s: " << s << std::endl;
	std::cout << "Value pointed to by stringPTR: " << stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
