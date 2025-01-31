/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:21:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 16:58:58 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap FragFrag("FragFrag");
	FragFrag.attack("TrapTrap");
	FragFrag.takeDamage(5);
	FragFrag.beRepaired(5);
	FragFrag.highFivesGuys();
}
