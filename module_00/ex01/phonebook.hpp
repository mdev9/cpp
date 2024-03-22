/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:05:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/22 18:23:37 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>

class	Contact;
class	PhoneBook;

std::string	space(int space_count);
void	right_print(std::string str);

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
	
	Contact();
	void	fill_contact_info();
	void	display_preview(int index);
	void	display_full();
};

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		next_contact_id;

	public:
	
	PhoneBook();
	void	replace_oldest_contact();
	void	add_contact();
	void	display_contacts();
	void	display_contact();
	void	search_contact();
};

#endif
