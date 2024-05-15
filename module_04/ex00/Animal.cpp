/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/15 10:46:20 by marde-vr         ###   ########.fr       */
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

void	Animal::makeSound() const
{
	if (_type == "Cat")
		std::cout << "Meow meow!" << std::endl;
	else if (_type == "Dog")
		std::cout << "Woof woof!" << std::endl;
	else
		std::cout << "Boo boo!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
