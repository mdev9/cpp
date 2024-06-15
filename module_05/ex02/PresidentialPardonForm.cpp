/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:12:37 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:38:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cp): AForm(cp)
{
	*this = cp;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isSigned())
	{
		if (executor.getGrade() <= getExecGrade())
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw FormIsNotSignedException();
}
