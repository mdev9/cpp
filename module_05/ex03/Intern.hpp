/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:30:15 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/14 15:55:48 by marde-vr         ###   ########.fr       */
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
};

#endif
