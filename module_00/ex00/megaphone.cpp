/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:05:47 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/21 08:33:15 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
			std::cout << (char)toupper(av[i][j]);
		if (i != ac - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
}
