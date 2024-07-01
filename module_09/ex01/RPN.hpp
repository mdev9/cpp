/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:14:40 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/01 11:41:34 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<int>	stack;
	
	public:
		RPN();
		RPN(std::string args);
		RPN(RPN& cp);
		RPN& operator=(RPN& other);
		~RPN();
		int	popTop();
		int	getRes();

	class ErrorException: public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif
