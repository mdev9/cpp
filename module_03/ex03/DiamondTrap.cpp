/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:38 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/15 10:13:23 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "_energyPoints: " << _energyPoints << std::endl;
	std::cout << "_hitPoints: " << _hitPoints << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << _name << std::endl;
	std::cout << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {}
