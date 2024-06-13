/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:15:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/13 13:41:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_is_signed = 0;
}

AForm::AForm(AForm& cp): _name(cp.getName()), _signGrade(cp.getSignGrade()), _execGrade(cp.getSignGrade())
{
	*this = cp;
}

AForm& AForm::operator=(AForm& other)
{
	if (this != &other)
	{
		_is_signed = other.isSigned();
	}
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::isSigned() const
{
	return _is_signed;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() <= _signGrade)
		_is_signed = 1;
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!\n";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!\n";
}

std::ostream &operator<<(std::ostream &out, const AForm& form)
{
	return out << form.getName() << "'s status:\n" << "signed: " << form.isSigned() << std::endl << "required grade to sign: " << form.getSignGrade() << std::endl << "required grade to execute: " << form.getExecGrade() << std::endl;
}
