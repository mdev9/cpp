/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:25:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 12:53:44 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie1 = NULL;
	Zombie* zombie2 = NULL;

	zombie1 = zombie1->newZombie("zombie1");
	zombie1->announce();
	delete zombie1;

	zombie2->randomChump("zombie2");
}
