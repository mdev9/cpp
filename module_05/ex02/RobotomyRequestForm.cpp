/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 07:51:47 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:05:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cp): AForm(cp)
{
	*this = cp;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* drilling noises *" << std::endl;
	std::cout << "* drilling noise intensifies *" << std::endl;
	std::cout << "* drilling noises go BRRRRR *" << std::endl;
	if (std::rand() % 2)
		std::cout << "Behold! " << _target << " emerges triumphantly from robotomization!" << std::endl;
	else
		std::cout << "Unfortunately, we regret to inform you that the robotomy of " << _target << " has failed due to unforeseen challenges :/" << std::endl;
}
