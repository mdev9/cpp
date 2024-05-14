/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:21:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 14:45:45 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ClapClap("ClapClap");
	ClapClap.attack("TrapTrap");
	ClapClap.takeDamage(5);
	ClapClap.beRepaired(5);
}
