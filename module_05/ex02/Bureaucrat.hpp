/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 13:24:08 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& cp);
		Bureaucrat& operator=(Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int			getGrade() const;
		void		upgrade();
		void		downgrade();

		void	signForm(Form &form);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc);

#endif
