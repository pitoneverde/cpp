/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:12:44 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/28 15:48:51 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP
#define __HARL_HPP 1

#include <string>
#include <iostream>

class Harl
{
private:
	void (Harl::*c)();

	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();

	void complain(std::string level);

	~Harl();
};

#endif