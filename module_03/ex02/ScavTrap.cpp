/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:22:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/16 09:55:34 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Constructor of ScavTrap " << name << " called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& cp): ClapTrap(cp._name)
{
	*this = cp;
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
	_name = other._name;
	_attackDamage = other._attackDamage;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "Destructor of ScavTrap " << _name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode!" << std::endl;
}
