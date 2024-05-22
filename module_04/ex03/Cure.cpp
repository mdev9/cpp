/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:27:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 15:39:06 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("ice") {}

Cure::Cure(Cure& cp): AMateria(cp._type) {}

Cure& Cure::operator=(Cure& other)
{
	return *other.clone();
}

Cure::~Cure() {}

Cure* Cure::clone() const
{
	Cure* Cure;
	return Cure;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
