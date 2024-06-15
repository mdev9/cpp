/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:22 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:12:03 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat highGrade("HighGrade", 1);
	Bureaucrat lowGrade("LowGrade", 150);

	ShrubberyCreationForm shrubberyForm("forest");
	RobotomyRequestForm robotomyForm("Bob");
	PresidentialPardonForm pardonForm("Bobby");
	try
	{
		highGrade.executeForm(robotomyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		shrubberyForm.beSigned(highGrade);
		highGrade.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		robotomyForm.beSigned(highGrade);
		highGrade.executeForm(robotomyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		pardonForm.beSigned(highGrade);
		highGrade.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		lowGrade.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		lowGrade.executeForm(robotomyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		lowGrade.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	return (0);
}
