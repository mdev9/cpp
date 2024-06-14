/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:22 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/14 13:12:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// Valid form 
	Form form1("Form1", 50, 25);
	std::cout << form1;
	// Invalid form, grade too high
	try
	{
		Form form2("Form2", 0, 25);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	// Invalid form, grade too low
	try
	{
		Form form3("Form3", 151, 25);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	Bureaucrat highGrade("HighGrade", 1);
	Bureaucrat lowGrade("LowGrade", 100);
	Form form4("Form4", 50, 25);
	// Invalid signing, grade too low
	lowGrade.signForm(form4);
	// Valid signing
	highGrade.signForm(form4);
	//Invalid signing, form already signed
	highGrade.signForm(form4);
	// Copy constructor
	Form form5(form4);
	// Copy assignment operator
	Form form6("Form6", 75, 50);
	form6 = form4;
	// Insertion operator
	std::cout << form4;
	std::cout << form5;
	std::cout << form6;
	return (0);
}
