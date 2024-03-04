/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:29:51 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/04 15:56:07 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& rhs);
		virtual ~Intern();
		Intern& operator=( const Intern& rhs);

		Form	*makeForm(std::string name, std::string target);

		class UnknownNameException: public std::exception{
			public:
				virtual const char*	what() const throw()  { return "It's an unknown format name."; }
		};
};

#endif
