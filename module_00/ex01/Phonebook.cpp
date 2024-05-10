/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:30:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/10 10:14:04 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook()
{
	next_contact_id = 1;
}

void	PhoneBook::replace_oldest_contact()
{
	int oldest_contact_id = contacts[0].id;

	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].id < oldest_contact_id)
			oldest_contact_id = contacts[i].id;
	}
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].id == oldest_contact_id)
			contacts[i].fill_all_contact_info();
	}
}

void	PhoneBook::add_contact()
{
	if (next_contact_id <= 8)
	{
		for (int i = 0; i < 8; i++)
		{
			if (contacts[i].id == 0)
			{
				contacts[i].fill_all_contact_info();
				contacts[i].id = next_contact_id;
				next_contact_id++;
				break;
			}
		}
	}
	else
	{
		std::cout << "Phone book is full, replacing oldest contact!\n";
		replace_oldest_contact();
	}
}

void PhoneBook::display_contacts()
{
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].id == 0)
			return;
		contacts[i].display_preview(i + 1);
	}
}

void PhoneBook::display_contact()
{
	std::string str_index;
	int index;
	int max_i;

	for (max_i = 0; max_i < 8; max_i++)
	{
		if (contacts[max_i].id == 0 && max_i == 0)
		{
			std::cout << "No contacts in phonebook :(\n";
			return;
		}
		if (contacts[max_i].id == 0)
			break;
	}
	std::cout << "Enter contact index (from 1 to " << max_i << ")\n";
	std::getline(std::cin, str_index);
	std::stringstream ss(str_index);
	ss >> index;
	if (index < 1 || index > max_i)
		std::cout << "Invalid contact index!\n";
	else
		contacts[index - 1].display_full();
}

void	PhoneBook::search_contact()
{
	PhoneBook::display_contacts();
	PhoneBook::display_contact();
}
