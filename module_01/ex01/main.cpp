/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:25:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 13:42:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies;
	int		nbOfZombies = 10;

	zombies = zombieHorde(nbOfZombies, "zombie");
	for (int i = 0; i < nbOfZombies ; i++)
		zombies[i].announce();

	delete[] zombies;
}
