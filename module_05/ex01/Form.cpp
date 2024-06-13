/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:15:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 13:32:51 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_is_signed = 0;
}

Form::Form(Form& cp): _name(cp.getName()), _signGrade(cp.getSignGrade()), _execGrade(cp.getSignGrade())
{
	*this = cp;
}

Form& Form::operator=(Form& other)
{
	if (this != &other)
	{
		_is_signed = other.isSigned();
	}
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _is_signed;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecGrade() const
{
	return _execGrade;
}

void	Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() <= _signGrade)
		_is_signed = 1;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!\n";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!\n";
}

std::ostream &operator<<(std::ostream &out, const Form& form)
{
	return out << form.getName() << "'s status:\n" << "signed: " << form.isSigned() << std::endl << "required grade to sign: " << form.getSignGrade() << std::endl << "required grade to execute: " << form.getExecGrade() << std::endl;
}
