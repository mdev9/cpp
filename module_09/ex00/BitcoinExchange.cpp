/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:00:06 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/26 15:22:37 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _database("data.csv")
{
	readDatabase();
}

BitcoinExchange::BitcoinExchange(std::string database): _database(database)
{
	readDatabase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& cp)
{
	*this = cp;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& other)
{
	_map = other._map;
	_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::readDatabase()
{
	//read database content, parse it and store it in _map
}

void	BitcoinExchange::setDatabase(std::string database)
{
	_database = database;
	readDatabase();
}

void	BitcoinExchange::exchange(std::string date, int amount)
{
	//check if args are valid
	//check if date exists, else get closest date (before)
	//print exchange info
}
