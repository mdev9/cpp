/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:13:43 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/01 11:33:14 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn.getRes() << std::endl;
	}
	catch (RPN::ErrorException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
