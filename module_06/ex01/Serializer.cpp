/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:38:14 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/18 10:50:30 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>

Serializer::Serializer() {}

Serializer::Serializer(Serializer& cp) {}

Serializer& Serializer::operator=(Serializer& other)
{
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
	
}

Data *Serializer::deserialize(uintptr_t raw)
{

}
