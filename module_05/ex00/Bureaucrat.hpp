/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:11 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 12:48:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
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

class Bureaucrat::GradeTooLowException: std::exception {};
class Bureaucrat::GradeTooHighException: std::exception {};

#endif
