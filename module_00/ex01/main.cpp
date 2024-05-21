/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:12:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/21 14:20:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>

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
