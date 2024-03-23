/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:33:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 12:34:01 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie( std::string name )
{
	Zombie *Zombie;
	
	Zombie = new class::Zombie();
	Zombie->name = name;
	return (Zombie);
}
