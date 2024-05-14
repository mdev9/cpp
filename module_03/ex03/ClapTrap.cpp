/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:38:06 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 17:00:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor of ClapTrap " << name << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& cp)
{
	std::cout << "Copy constructor called\n";
	*this = cp;
}

ClapTrap& ClapTrap::operator=(ClapTrap& cp)
{
	std::cout << "Copy assignment operator called\n";
	_name = cp._name;
	_hitPoints = cp._hitPoints;
	_energyPoints = cp._hitPoints;
	_attackDamage = cp._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap " << _name << " called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints && _energyPoints)
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself and got " << amount << " hit points back!" << std::endl;
		_energyPoints--;
	}
}
