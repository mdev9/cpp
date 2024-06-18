/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:08:24 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/18 10:34:55 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
		ScalarConverter::convert(argv[1]);
}
