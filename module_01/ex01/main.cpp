/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:25:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 13:39:30 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies;
	zombies = zombieHorde(10, "zombie");

	for (int i = 0; i < 10 ; i++)
		zombies[i].announce();

	delete[] zombies;
}
