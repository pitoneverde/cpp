/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:28:07 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/26 00:19:04 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char const *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEAREABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		int j = 0;
		while (argv[i] && argv[i][j] != '\0') {
			// casting to char to not get a string made of ascii codes
			std::cout << (char)std::toupper(static_cast<unsigned char>(argv[i][j]));
			j++;
		}
	}
	std::cout << std::endl;
	return 0;
}
