/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:30:02 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/30 18:10:34 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	// read input file
	std::string file;
	{
		std::ifstream ifs(argv[1]);
		if (!ifs.is_open()) {
			std::cout << "Error opening file: " << argv[1] << std::endl;
			return 1;
		}
		std::string s;
		while (std::getline(ifs, s)) {
			file.append(s);
		}
	}	// call ifs' destructor

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	size_t	to_replace = file.find(s1);
	while (to_replace != std::string::npos) {
		file.erase(to_replace, s1.length());
		file.insert(to_replace, s2);
		to_replace = file.find(s1, to_replace);
	}
	
	// create and output to file.replace
	std::string filename = argv[1];
	filename += ".replace";
	{
		std::ofstream ofs(filename.c_str());
		if (!ofs.is_open()) {
			std::cout << "Error saving file: " << filename << std::endl;
			return 1;
		}
		ofs << file;
	}	// call ofs' destructor
	return 0;
}
