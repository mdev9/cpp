/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:28:31 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 14:46:06 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	setType(type);
}

const std::string	&Weapon::getType()
{
	return (type);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}
