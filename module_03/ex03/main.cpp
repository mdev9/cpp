/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:21:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/07 10:58:39 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap Diamond("DiamondTrap");
	Diamond.attack("TrapTrap");
	Diamond.whoAmI();
	Diamond.guardGate();
	Diamond.highFivesGuys();
}
