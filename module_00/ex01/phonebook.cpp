/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:07:48 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/22 11:19:17 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Contact
{
	char	*first_name;
	char	*last_name;
	char	*nickname;
	int		phone_number;
	char	*darkes_secret;
};

class	PhoneBook
{
	private:
		Contact	contacts[8];

	//constructor: construct contacts
	void	add_contact();
	void	search_contact();
};

int	main(void)
{
	PhoneBook	phonebook;
	char		*input;

	while (input_valid() && no_exit())
	{
		
		std::cin >> input;
	}
}
