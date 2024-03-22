/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:30:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/22 17:07:12 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		std::string	phone_number;

	public:
		int		id;
	
	Contact()
	{
		id = 0;
	}

	void	fill_contact_info()
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

	void	display_preview(int index)
	{
		std::cout << index << '|'
		<< first_name.substr(0, 10) << '|'
		<< last_name.substr(0, 10) << '|'
		<< nickname.substr(0, 10) << '\n';
	}

	void	display_full()
	{
		std::cout << first_name << '\n';
		std::cout << last_name << '\n';
		std::cout << nickname << '\n';
		std::cout << phone_number << '\n';
		std::cout << darkest_secret << '\n';
	}
};

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		next_contact_id;

	public:
	
	
	PhoneBook()
	{
		next_contact_id = 1;
	}

	void	replace_oldest_contact()
	{
		int oldest_contact_id = contacts[0].id;

		for (int i = 1; i < 8; i++)
		{
			if (contacts[i].id < oldest_contact_id)
				oldest_contact_id = contacts[i].id;
		}
		contacts[oldest_contact_id].fill_contact_info();
	}

	void	add_contact()
	{
		if (next_contact_id <= 8)
		{
			for (int i = 0; i < 8; i++)
			{
				if (contacts[i].id == 0)
				{
					std::cout << "Editing " << i << '\n';
					contacts[i].fill_contact_info();
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

	void display_contacts()
	{
		for (int i = 0; i < 8; i++)
		{
			if (contacts[i].id == 0)
				return;
			contacts[i].display_preview(i + 1);
		}
	}

void display_contact()
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

	void	search_contact()
	{
		display_contacts();
		display_contact();
	}
};

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Choose an action from ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			exit(0);
		else
			std::cout << "Invalid input!\n";
		//std::cin.clear();
	}
	return (0);
}
