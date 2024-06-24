/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:38:38 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/24 13:04:31 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class NoOccurenceFoundException: public std::exception
{
	public:
		virtual const char	*what(void) const throw()
		{
			return "No occurence found";
		}
};

template <typename T> T easyfind(T container, int integer)
{
	T iterator = std::find(container.begin(), container.end(), integer);
	if (iterator != container.end())
		std::cout << "Found " << integer << " at position " << iterator - container.begin() << std::endl;
	else
		throw NoOccurenceFoundException();
}

#endif
