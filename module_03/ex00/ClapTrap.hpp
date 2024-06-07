/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/07 10:46:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{	
	private:
		std::string _name;
		int _hitPoints;
		int	_energyPoints;
		int	_attackDamage;
	
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& cp);
		ClapTrap& operator=(ClapTrap& cp);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
