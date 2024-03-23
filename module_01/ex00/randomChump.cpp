/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:34:29 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 12:34:31 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::randomChump( std::string name )
{
	Zombie Zombie;
	
	Zombie.name = name;
	Zombie.announce();
}
