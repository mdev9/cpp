/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:00:06 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 11:28:48 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database("data.csv")
{
	readDatabase();
}

BitcoinExchange::BitcoinExchange(std::string database) : _database(database)
{
	readDatabase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &cp)
{
	*this = cp;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	_map = other._map;
	_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	//delete map
}

bool	isDateValid(int day, int month, int year)
{
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;
	if (!(year % 4) && month == 2)
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

bool	isStrDateValid(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] !='-')
		return false;

	int year, month, day;
	char dash1, dash2;

	std::istringstream dateStream(date);
	if (!(dateStream >> year >> dash1 >> month >> dash2 >> day))
		return false;

	return isDateValid(day, month, year);
}

void BitcoinExchange::readDatabase()
{
	std::ifstream infile(_database.c_str());
	std::string line;
	if (infile.is_open())
	{
		std::getline(infile, line);
		if (line != "date,exchange_rate")
		{
			infile.close();
			throw InvalidDatabaseException();
		}
		while (infile)
		{
			std::getline(infile, line);
			if (line != "\n" && !line.empty())
				this->readEntry(line);
		}
	}
	else
		std::cout << "Couldn't open file " << _database << std::endl;
}

void BitcoinExchange::readEntry(std::string entry)
{
	std::string date = entry.substr(0, entry.find(','));
	int separatorIndex = entry.find(',');
	if (!separatorIndex || !isStrDateValid(date))
		throw BitcoinExchange::InvalidDatabaseEntryException();
	std::string strValue = entry.substr(separatorIndex + 1, entry.npos);
	float value = atof(strValue.c_str());
	if ((!value && strValue[0] != '0') || value < 0)
		throw BitcoinExchange::InvalidDatabaseEntryException();

	_map.insert(std::pair<std::string, float>(date, value));
}

void BitcoinExchange::setDatabase(std::string database)
{
	_database = database;
	readDatabase();
}

void BitcoinExchange::exchange(std::string entry)
{
	std::string date = entry.substr(0, entry.find(' '));
	int separatorIndex = entry.find('|');
	if (!separatorIndex || !isStrDateValid(date))
	{
		std::cout << "Error: bad input => " << entry << std::endl;
		return;
	}
	std::string strAmount = entry.substr(separatorIndex + 1, entry.npos);
	float amount = atof(strAmount.c_str());
	if (!amount && strAmount[0] != '0')
	{
		std::cout << "Error: bad input => " << entry << std::endl;
		return;
	}
	if (amount < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (amount > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	std::cout << date << " => " << amount << " = " << getValue(date) * amount << std::endl;
}

float BitcoinExchange::getValue(std::string date)
{
	std::map<std::string, float>::iterator itr;
	std::map<std::string, float>::iterator itr_closest = _map.begin();
	size_t closest_i = 0;
	for (itr = _map.begin(); itr != _map.end(); ++itr)
	{
		std::string curr_date = itr->first;
		size_t i = 0;
		while (curr_date[i] == date[i] && i < date.length())
			i++;
		if (i == date.length())
			return itr->second;
		else if (i > closest_i || (i == closest_i && curr_date[i] < date[i]))
		{
			closest_i = i;
			itr_closest = itr;
		}
	}
	return itr_closest->second;
}

const char *BitcoinExchange::InvalidDatabaseException::what(void) const throw()
{
	return "Error: invalid database file!";
}

const char *BitcoinExchange::InvalidDatabaseEntryException::what(void) const throw()
{
	return "Error: invalid database entry!";
}
