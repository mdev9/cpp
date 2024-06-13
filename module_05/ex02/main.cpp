/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:22 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 13:29:41 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// Valid form 
	try
	{
		Form form1("Form1", 50, 25);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// Invalid form, grade too high
	try
	{
		Form form2("Form2", 0, 25);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// Invalid form, grade too low
	try
	{
		Form form3("Form3", 151, 25);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	Bureaucrat highGrade("HighGrade", 1);
	Bureaucrat lowGrade("LowGrade", 100);
	Form form4("Form4", 50, 25);
	// Valid signing
	try
	{
		form4.beSigned(highGrade);
		std::cout << highGrade.getName() << " signed " << form4.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << highGrade.getName() << " couldn't sign " << form4.getName() << " because " << e.what() << std::endl;
	}
	// Invalid signing
	try
	{
		form4.beSigned(lowGrade);
	}
	catch (const std::exception &e)
	{
		std::cerr << lowGrade.getName() << " couldn't sign " << form4.getName() << " because " << e.what() << std::endl;
	}
	Form form5(form4);
	// Copy constructor
	Form form6("Form6", 75, 50);
	// Using copy assignment operator
	form6 = form4;
	// Insertion operator
	std::cout << form4;
	std::cout << form5;
	std::cout << form6;
	return (0);
}
