/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:03 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 10:29:02 by marde-vr         ###   ########.fr       */
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
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat& cp) : _name(cp._name)
{
	*this = cp;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::upgrade()
{
	if (this->getGrade() > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::downgrade()
{
	if (this->getGrade() < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!\n";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc)
{
	return out << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".\n";
}
