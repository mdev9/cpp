/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:05 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/20 10:28:43 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	Animal::_type = "Dog";
	_brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog& cp)
{
	_type = cp._type;
	_brain = new Brain;
	*_brain = *(cp._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog& other)
{
	_type = other._type;
	_brain = new Brain;
	*_brain = *other._brain;
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}
