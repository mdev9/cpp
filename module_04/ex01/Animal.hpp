/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/22 10:45:29 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class	Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal& cp);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void	makeSound() const;
		std::string getType() const;
};

#endif
