/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:10:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/24 09:35:36 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];

	public:
		Character(const std::string& name);
		Character(const Character& cp);
		Character& operator=(const Character& other);
		~Character();
		std::string const& getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
