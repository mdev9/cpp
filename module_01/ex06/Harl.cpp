/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:48:36 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 15:32:54 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	Harl::getLevel(std::string level, const std::string levels[4])
{
	if (level == levels[0])
		return (0);
	else if (level == levels[1])
		return (1);
	else if (level == levels[2])
		return (2);
	else if (level == levels[3])
		return (3);
	else
		return (4);
}

void	Harl::showLevel(int i)
{
	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			break;
		case 1:
			std::cout << "[ INFO ]\n";
			break;
		case 2:
			std::cout << "[ WARNING ]\n";
			break;
		case 3:
			std::cout << "[ ERROR ]\n";
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

void	Harl::complain(std::string level)
{
	void (Harl::*HarlMemFun[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i <= 4; i++)
	{
		if (i >= Harl::getLevel(level, levels))
		{
			Harl::showLevel(i);
			if (i < 4)
				(this->*HarlMemFun[i])();
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
