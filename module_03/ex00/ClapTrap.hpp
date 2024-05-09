/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:08 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/09 15:45:37 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	std::string _Name;
	int _hitPoints = 10;
	int	_energyPoints = 10;
	int	_attackDamage = 0;
	
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
}

#endif
