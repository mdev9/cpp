/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:49:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/10 10:34:58 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource& cp)
{
	for (int i = 0; i < 4; i++)
	{
		if (cp._templates[i])
			_templates[i] = cp._templates[i]->clone();
		else
			_templates[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	if (type.empty())
		return 0;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
