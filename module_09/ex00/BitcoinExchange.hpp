/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:01:06 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 11:28:11 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

#include <exception>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _map;
		std::string _database;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string database);
		BitcoinExchange(BitcoinExchange& cp);
		BitcoinExchange& operator=(BitcoinExchange& other);
		~BitcoinExchange();
		void	exchange(std::string entry);
		void	setDatabase(std::string database);
		void	readDatabase();
		void	readEntry(std::string entry);
		float	getValue(std::string date);

		class InvalidDatabaseException: public std::exception
		{
			public:
				const char	*what(void)	const throw();
		};
		class InvalidDatabaseEntryException: public std::exception
		{
			public:
				const char	*what(void)	const throw();
		};
};

#endif
