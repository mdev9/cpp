/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:05:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 07:37:41 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		oldest_contact_id;

	public:
	
	PhoneBook();
	void	replace_oldest_contact();
	void	add_contact();
	void	display_contacts();
	void	display_contact();
	void	search_contact();
};

#endif
