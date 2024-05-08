/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:24:05 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 14:43:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int ac, char **av)
{
	Harl Harl;

	if (ac != 2)
		return (1);
	std::string level = av[1];
	Harl.complain(level);
}
