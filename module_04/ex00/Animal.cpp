/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 10:45:08 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "undefined";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& cp): _type(cp._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignement constructor called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}	

std::string Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "Boo boo!" << std::endl;
}
