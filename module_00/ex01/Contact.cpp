/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:11:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 14:12:08 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Contact::Contact()
{
	id = 0;
}

void	Contact::fill_contact_info()
{
	std::cout << "Input first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Input last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Input nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Input phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Input darkest secret: ";
	std::getline(std::cin, darkest_secret);
	std::cout << "Succesfully saved new contact!\n";
}

void	Contact::display_preview(int index)
{
	std::cout << space(9) << index << '|';
	right_print(first_name);
	std::cout << '|';
	right_print(last_name);
	std::cout << '|';
	right_print(nickname);
	std::cout << '\n';
}

void	Contact::display_full()
{
	std::cout << first_name << '\n';
	std::cout << last_name << '\n';
	std::cout << nickname << '\n';
	std::cout << phone_number << '\n';
	std::cout << darkest_secret << '\n';
}
