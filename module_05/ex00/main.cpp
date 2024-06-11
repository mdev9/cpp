/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:26:20 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/11 10:39:46 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat Bob("Bob", 10);
	Bob.getGrade();
	//Bob.upgrade();
	Bob.getGrade();
	//Bob.downgrade();
	Bob.getGrade();

	try
	{
		Bureaucrat Bobby("Bobby", 170);
	}
	catch (std::exception &e)
	{
		//oui
	}

	try
	{
		Bureaucrat Bobbito("Bobbito", 0);
	}
	catch (std::exception &e)
	{
		//ok
	}
	
	return 0;
}
