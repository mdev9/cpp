/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:03 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 16:40:40 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException : public exception
{
	const char * what() const throw ()
	{
		return "Grade too high!"
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade >= 1 && grade <= 150)
			_grade = grade;
		else
			throw (grade);
	}
	catch (int grade)
	{

	}

}

Bureaucrat::Bureaucrat(Bureaucrat& cp)
{
	_name = cp.getName();
	_grade = cp.getGrade();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other.getName();
		_grade = other.getGrade();
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


