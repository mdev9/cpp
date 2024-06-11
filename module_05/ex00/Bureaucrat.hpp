/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/11 10:25:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		std::string getName();
		int			getGrade();
		void		upgrade();
		void		downgrade();

		class GradeTooHighException;
		class GradeTooLowException;
};

//TODO: Implement insertion operator overload

class Bureaucrat::GradeTooLowException: public std::exception {
	const char	*what(void) const throw();
};
class Bureaucrat::GradeTooHighException: public std::exception {
	const char	*what(void) const throw();
};

#endif
