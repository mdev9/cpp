/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:01:38 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/21 10:56:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	ScavTrap::_energyPoints = 50;
	std::cout << "_energyPoints: " << _energyPoints << std::endl;
	std::cout << "_hitPoints: " << _hitPoints << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& cp): ClapTrap(cp._name + "_clap_name"), ScavTrap(cp._name), FragTrap(cp._name)
{
	*this = cp;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << _name << std::endl;
	std::cout << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {}
