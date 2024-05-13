/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:12:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/11 08:57:54 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

std::string	space(int space_count)
{
	if (space_count <= 0)
		return ("");
	return (" " + space(space_count - 1));
}

void	right_print(std::string str)
{
	int len;

	len = str.length();
	if (len > 9)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << space(10 - len) << str;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << "Choose an action from ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT" || std::cin.eof())
			exit(0);
		else
			std::cout << "Invalid input!\n";
	}
	return (0);
}
