/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:27:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/24 09:28:27 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& cp);
		Cure& operator=(const Cure& other);
		~Cure();
		Cure	*clone() const;
		void	use(ICharacter &target);
};

#endif
