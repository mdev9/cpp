/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:12:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 07:41:06 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int exit = 0;

	while (!std::cin.eof() && !exit)
	{
		std::cout << "Choose an action from ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT" || std::cin.eof())
			exit = 1;
		else
			std::cout << "Invalid input!\n";
	}
	return (0);
}
