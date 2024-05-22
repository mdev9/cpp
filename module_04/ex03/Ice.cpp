/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:27:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 15:35:43 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice& cp): AMateria(cp._type) {}

Ice& Ice::operator=(Ice& other)
{
	return *other.clone();
}

Ice::~Ice() {}

Ice* Ice::clone() const
{
	Ice* Ice;
	return Ice;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
