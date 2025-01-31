/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:39:35 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 10:54:26 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern &cp)
{
	*this = cp;
}

Intern& Intern::operator=(Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	struct Forms
	{
		std::string name;
		AForm* (Intern::*createForm)(std::string target);
	};

	Forms forms[] = {
		{"shrubbery creation", &Intern::makeShrubberyCreationForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"presidential pardon", &Intern::makePresidentialPardonForm}
	};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (forms[i].name == name)
			{
				std::cout << "Intern creates " << name << std::endl;
				return (this->*forms[i].createForm)(target);
			}
		}
		throw UnknownFormException();
	}
	catch (const UnknownFormException &e)
	{
		std::cout << "Intern can't create form " << name << " because:" << std::endl << e.what() << "Bringing some coffee instead!" << std::endl;
	}
	return 0;
}

AForm*	Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

const char	*Intern::UnknownFormException::what(void) const throw()
{
	return "Form doesn't exist!\n";
}
