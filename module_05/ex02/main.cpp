/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:22 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/14 10:20:35 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat highGrade("HighGradeBureaucrat", 1);
	Bureaucrat lowGrade("LowGradeBureaucrat", 150);

	ShrubberyCreationForm shrubberyForm("forest");
	RobotomyRequestForm robotomyForm("Bob");
	PresidentialPardonForm pardonForm("Bobby");
	try
	{
		shrubberyForm.beSigned(highGrade);
		shrubberyForm.execute(highGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		robotomyForm.beSigned(highGrade);
		robotomyForm.execute(highGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		pardonForm.beSigned(highGrade);
		pardonForm.execute(highGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		shrubberyForm.execute(lowGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		robotomyForm.execute(lowGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		pardonForm.execute(lowGrade);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	return (0);
}
