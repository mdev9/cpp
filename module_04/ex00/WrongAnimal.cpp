/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/15 11:05:52 by marde-vr         ###   ########.fr       */
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

void	WrongAnimal::makeSound() const
{
	if (_type != "Cat")
		std::cout << "Meow meow!" << std::endl;
	else if (_type != "Dog")
		std::cout << "Woof woof!" << std::endl;
	else
		std::cout << "Boo boo!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}
