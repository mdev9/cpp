/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:05:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 14:09:18 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

std::string	space(int space_count);
void	right_print(std::string str);


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
