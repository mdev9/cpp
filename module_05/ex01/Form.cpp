/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:15:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/14 12:52:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(0) , _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form& cp): _name(cp.getName()), _signGrade(cp.getSignGrade()), _execGrade(cp.getSignGrade())
{
	*this = cp;
}

Form& Form::operator=(Form& other)
{
	if (this != &other)
	{
		_isSigned = other.isSigned();
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
	return _isSigned;
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
	{
		_isSigned = 1;
		std::cout << bc.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << bc.getName() << " couldn't sign " << this->getName() << " because his grade is too low!" << std::endl;
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
	return out << form.getName() << "'s status:\n" << "signed: " << form.isSigned() << std::endl << "required _signGrade to sign: " << form.getSignGrade() << std::endl << "required grade to execute: " << form.getExecGrade() << std::endl;
}
