/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 07:18:03 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:42:03 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("unknown"), _tree("       _-_       \n    /~~   ~~\\    \n /~~         ~~\\ \n{               }\n \\  _-     -_  / \n   ~  \\\\ //  ~   \n_- -   | | _- _  \n  _ -  | |   -_  \n      // \\\\      \n") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target), _tree("       _-_       \n    /~~   ~~\\    \n /~~         ~~\\ \n{               }\n \\  _-     -_  / \n   ~  \\\\ //  ~   \n_- -   | | _- _  \n  _ -  | |   -_  \n      // \\\\      \n") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cp): AForm(cp)
{
	*this = cp;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (isSigned())
	{
		if (executor.getGrade() <= getExecGrade())
		{
			std::ofstream outfile((_target + "_shrubbery").c_str());
			if (outfile.is_open())
			{
				for (int i = 0; i < 3; i++)
					outfile << _tree << std::endl;
				outfile.close();
			}
			else
				std::cout << "Couldn't open file " << _target + "_shrubbery" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormIsNotSignedException();
}
