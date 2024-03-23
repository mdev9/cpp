/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:31:42 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 15:39:55 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	Weapon		*Weapon;
	std::string	name;
	
	public:

	HumanB(std::string name);
	void	attack();
	void	setWeapon(class Weapon Weapon);
};

#endif
