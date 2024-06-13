/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:26:20 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 10:33:07 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		// Valid grade
		Bureaucrat Bob("Bob", 75);
		//Getters
		std::cout << Bob.getGrade() << std::endl;
		std::cout << Bob.getName() << std::endl;
		//Operator overload
		std::cout << Bob;
		//Copy constructor
		Bureaucrat Bobby(Bob);
		std::cout << Bobby;
		//Copy assignment operator
		Bureaucrat Bobby2("Bobby2", 10);
		Bobby2 = Bob;
		std::cout << Bobby2;
	}
	{
		//Invalid grade too high
		try
		{
			Bureaucrat Bob("Bob", 0);
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what();
		}
	}
	{
		//Invalid grade too low
		try
		{
			Bureaucrat Bob("Bob", 151);
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what();
		}
	}
	{
		//Increment grade
		Bureaucrat Bob("Bob", 75);
		Bob.upgrade();
		std::cout << Bob.getGrade() << std::endl;
	}
	{
		//Increment grade too high
		Bureaucrat Bob("Bob", 1);
		try
		{
			Bob.upgrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what();
		}
		std::cout << Bob.getGrade() << std::endl;
	}
	{
		//Decrement grade
		Bureaucrat Bob("Bob", 75);
		Bob.downgrade();
		std::cout << Bob.getGrade() << std::endl;
	}
	{
		//Decrement grade too low
		Bureaucrat Bob("Bob", 150);
		try
		{
			Bob.downgrade();
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what();
		}
		std::cout << Bob.getGrade() << std::endl;
	}
	return 0;
}
