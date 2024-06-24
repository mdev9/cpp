/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:38:38 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/24 14:22:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class NoOccurenceFoundException: public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return "No occurence found";
		}
};

template <typename T> typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end())
		throw NoOccurenceFoundException();
	return iterator;
}

#endif
