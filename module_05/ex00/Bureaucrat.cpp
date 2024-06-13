/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:03 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 08:15:59 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat& cp) : _name(cp._name)
{
	*this = cp;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		//_name = other._grade;
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
	return _name;
}

int	Bureaucrat::getGrade()
{
	return _grade;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc)
{
	out << bc.getName << ", bureaucrat grade " << bc.getGrade << ".\n";
}
