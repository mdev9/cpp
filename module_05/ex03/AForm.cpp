/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:15:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/14 14:21:01 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _isSigned(0) , _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm& cp): _name(cp.getName()), _signGrade(cp.getSignGrade()), _execGrade(cp.getSignGrade())
{
	*this = cp;
}

AForm& AForm::operator=(AForm& other)
{
	if (this != &other)
	{
		_isSigned = other.isSigned();
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
	return _isSigned;
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
	if (bc.getGrade() <= _signGrade && !isSigned())
		_isSigned = 1;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!\n";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!\n";
}

const char *AForm::FormIsNotSignedException::what(void) const throw()
{
	return "The form is not signed!\n";
}

std::ostream &operator<<(std::ostream &out, const AForm& form)
{
	return out << form.getName() << "'s status:\n" << "signed: " << form.isSigned() << std::endl << "required grade to sign: " << form.getSignGrade() << std::endl << "required grade to execute: " << form.getExecGrade() << std::endl;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_isSigned)
	{
		if (executor.getGrade() <= _execGrade)
			executeAction();
		else
			throw GradeTooLowException();
	}
	else
		throw FormIsNotSignedException();
}
