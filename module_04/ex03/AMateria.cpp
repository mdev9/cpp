/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:46:17 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 14:42:01 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(AMateria& cp): _type(cp._type) {}

AMateria& AMateria::operator=(AMateria& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return _type;
}
