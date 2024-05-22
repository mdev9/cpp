/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 13:12:30 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "undefined";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp): _type(cp._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignement constructor called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}	

std::string WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Boo boo!" << std::endl;
}
