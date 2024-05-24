/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:27:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/24 09:27:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& cp);
		Ice& operator=(const Ice& other);
		~Ice();
		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif
