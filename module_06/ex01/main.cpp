/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:37:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/19 10:04:02 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data *data;
	Data *data2;

	data->city = "Angoulêne";
	data->year = 2024;
	data->liquid = "water";
	data->number = 42;

	data2 = Serializer::deserialize(Serializer::serialize(data));
	if (data == data2)
		std::cout << true << std::endl;
	else
		std::cout << false << std::endl;

	std::cout << data2->city << std::endl;
	std::cout << data2->year << std::endl;
	std::cout << data2->liquid << std::endl;
	std::cout << data2->number << std::endl;
}
