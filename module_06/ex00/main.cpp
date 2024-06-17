/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:08:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/17 08:15:10 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ScalarConverter sc;
		sc.convert(argv[1]);
	}
}
