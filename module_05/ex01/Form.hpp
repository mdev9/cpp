/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:36:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 11:36:58 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _signGrade;
		const int _execGrade;
	
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form& cp);
		Form& operator=(Form& other);
		~Form();

		std::string	getName() const;
		bool	isSigned() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		void	beSigned(Bureaucrat &bc);

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

std::ostream &operator<<(std::ostream &out, const Form& Form);

#endif
