/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:37:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/21 14:49:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	*_ideas = new std::string[100];
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain& cp)
{
	*_ideas = new std::string[100];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	*_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain()
{
	delete[] *_ideas;
	std::cout << "Brain destructor called" << std::endl;
}
