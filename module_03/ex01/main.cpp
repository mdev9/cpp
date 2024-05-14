/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:21:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 15:34:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap ScavScav("ScavScav");
	ScavScav.attack("TrapTrap");
	ScavScav.takeDamage(5);
	ScavScav.beRepaired(5);
	ScavScav.guardGate();
}
