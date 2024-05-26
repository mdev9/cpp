/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:09:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/26 08:29:26 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(const std::string& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& cp): _name(cp._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (cp._inventory[i])
			_inventory[i] = cp._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (!_inventory[idx] || idx < 0 || idx >= 4)
		return;
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx] || idx < 0 || idx >= 4)
		return;
	_inventory[idx]->use(target);
}
