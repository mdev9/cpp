/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:44:03 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 08:55:48 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form;

Bureaucrat::Bureaucrat(): _name("unknown"), _grade(150) {}

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


void	Bureaucrat::signForm(AForm &form)
{
	if (!form.isSigned())
	{
		if (_grade <= form.getSignGrade())
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		else
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low :c" << std::endl;
	}
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because it is already signed!" << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << ':' << std::endl << e.what();
		return;
	}
	std::cout << _name << " executed " << form.getName() << std::endl;
}
