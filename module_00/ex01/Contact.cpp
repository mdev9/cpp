/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:11:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/25 10:21:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>


Contact::Contact()
{
	id = 0;
}

Contact::~Contact() {}

void	Contact::fill_contact_info(std::string prompt, std::string& info)
{
	if (std::cin.eof())
		return ;
	std::cout << prompt;
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	if (info.empty())
		fill_contact_info(prompt, info);
}

void	Contact::fill_all_contact_info()
{
	fill_contact_info("Input first name: ", first_name);
	fill_contact_info("Input last name: ", last_name);
	fill_contact_info("Input nickname: ", nickname);
	fill_contact_info("Input phone number: ", phone_number);
	fill_contact_info("Input darkest secret: ", darkest_secret);
	if (std::cin.eof())
		return ;
	std::cout << "Succesfully saved new contact!" << std::endl;
}

void	right_print(std::string str)
{
	int len;

	len = str.length();
	if (len > 9)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

void	Contact::display_preview(int index)
{
	std::cout << std::setw(9) << index << '|';
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
