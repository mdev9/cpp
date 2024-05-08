/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:45:15 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 15:23:46 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		void	complain(std::string level);
	
	int		getLevel(std::string level, const std::string levels[4]);
	void	showLevel(int i);
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
