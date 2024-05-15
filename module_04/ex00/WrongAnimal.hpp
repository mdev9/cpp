/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:20:53 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/15 13:34:16 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		virtual	~WrongAnimal();
		void	makeSound() const;
		std::string	getType() const;
};

#endif
