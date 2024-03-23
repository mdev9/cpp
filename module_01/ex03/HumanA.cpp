/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:34:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/23 15:49:54 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>

HumanA::HumanA(std::string name, Weapon& weapon)
{

}

void	HumanA::attack()
{
	std::cout << name << "attacks with their " << Weapon.getType() << std::endl;
}
