/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:01:06 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/26 15:18:29 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, int> _map;
		std::string _database;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string database);
		BitcoinExchange(BitcoinExchange& cp);
		BitcoinExchange& operator=(BitcoinExchange& other);
		~BitcoinExchange();
		void	exchange(std::string date, int amount);
		void	setDatabase(std::string database);
		void	readDatabase();
};

#endif
