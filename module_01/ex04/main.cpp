/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:40:47 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 11:53:33 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"
#include <iostream>

int	main(void)
{
	std::string args[4] = {0, "test", "marde-vr", "hahahaha"};
	replace(4, args);
}
