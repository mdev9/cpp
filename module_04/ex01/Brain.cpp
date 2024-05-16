/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:37:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/16 13:54:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	*_ideas = new std::string[100];
}

Brain::Brain(Brain& cp)
{
	*this = cp;	
}

Brain& Brain::operator=(Brain& other)
{
	*_ideas = *other._ideas;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
