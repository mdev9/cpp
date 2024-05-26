/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:07 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/26 08:59:09 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& cp);
		Cat& operator=(const Cat& other);
		~Cat();
		virtual void makeSound() const;
		void setIdea(std::string idea, int index);
		std::string	getIdea(int index);
};

#endif
