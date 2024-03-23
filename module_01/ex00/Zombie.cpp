/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:06:47 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 12:50:08 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <ostream>

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed!\n";
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
