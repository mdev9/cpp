/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:31:42 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/10 14:51:09 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	Weapon		*_weapon;
	std::string	_name;
	
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon& weapon);
};

#endif
