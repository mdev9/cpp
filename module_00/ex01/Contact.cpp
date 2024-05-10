/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:11:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/10 16:29:47 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>


Contact::Contact()
{
	id = 0;
}

void	Contact::fill_contact_info(std::string prompt, std::string* info)
{
	std::cout << prompt;
	std::getline(std::cin, *info);
	if (std::cin.eof())
		std::exit(0);
	if (info->empty())
		fill_contact_info(prompt, info);
}

void	Contact::fill_all_contact_info()
{
	fill_contact_info("Input first name: ", &first_name);
	fill_contact_info("Input last name: ", &last_name);
	fill_contact_info("Input nickname: ", &nickname);
	fill_contact_info("Input phone number: ", &phone_number);
	fill_contact_info("Input darkest secret: ", &darkest_secret);
	std::cout << "Succesfully saved new contact!" << std::endl;
}

void	Contact::display_preview(int index)
{
	std::cout << space(9) << index << '|';
	right_print(first_name);
	std::cout << '|';
	right_print(last_name);
	std::cout << '|';
	right_print(nickname);
	std::cout << std::endl;
}

void	Contact::display_full()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
}
