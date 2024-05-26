/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/26 08:58:09 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog& cp);
		Dog& operator=(const Dog& other);
		~Dog();
		virtual void makeSound() const;
		void setIdea(std::string idea, int index);
		std::string	getIdea(int index);
};

#endif
