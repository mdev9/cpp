/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:45:15 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/24 09:04:40 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
# define MATERIASOURCE

#include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _templates[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource& cp);
		MateriaSource& operator=(MateriaSource& other);
		~MateriaSource();
		void	learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);
};

#endif
