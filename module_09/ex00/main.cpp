/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:02:35 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/27 09:45:55 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream infile(argv[1]);
	std::string line;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btcExchange;
		if (infile.is_open())
		{
			std::getline(infile, line);
			if (line != "date | value")
			{
				std::cout << "Error: invalid input file!" << std::endl;
				infile.close();
				return 1;
			}
			while (infile)
			{
				std::getline(infile, line);
				if (line != "\n" && !line.empty())
					btcExchange.exchange(line);
			}
			infile.close();
		}
		else
			std::cout << "Couldn't open file " << argv[1] << std::endl;
	}
	catch (BitcoinExchange::InvalidDatabaseException &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
