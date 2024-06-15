/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:36:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:35:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm& cp);
		AForm& operator=(AForm& other);
		~AForm();

		std::string	getName() const;
		bool	isSigned() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		void	beSigned(Bureaucrat &bc);

		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		class FormIsNotSignedException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm& AForm);

#endif
