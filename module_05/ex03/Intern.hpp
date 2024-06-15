/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:30:15 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:23:43 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		AForm*	makeForm(std::string name, std::string target);
		AForm*	makeShrubberyCreationForm(std::string target);
		AForm*	makeRobotomyRequestForm(std::string target);
		AForm*	makePresidentialPardonForm(std::string target);

		Intern();
		Intern(Intern &cp);
		Intern& operator=(Intern &other);
		~Intern();

		class UnknownFormException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
