/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:22 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/15 09:28:36 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* form4;

    form1 = intern.makeForm("shrubbery creation", "forest");
	delete form1;
    form2 = intern.makeForm("robotomy request", "Bob");
	delete form2;
    form3 = intern.makeForm("presidential pardon", "Bobby");
	delete form3;
    form4 = intern.makeForm("unknown form", "Nobody");

    return 0;
}
