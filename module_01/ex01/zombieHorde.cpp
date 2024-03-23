/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:56:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 13:37:13 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*Zombies;

	Zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		Zombies[i].setName(name);
	}
	return (Zombies);
}
