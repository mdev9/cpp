/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 13:11:39 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& cp);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();
		void makeSound() const;
};

#endif
