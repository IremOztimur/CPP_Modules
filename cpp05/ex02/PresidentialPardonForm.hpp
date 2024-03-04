/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:47:09 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/04 09:54:19 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public Form{
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		PresidentialPardonForm&  operator=(PresidentialPardonForm &rhs);

		void					execute(const Bureaucrat& executor) const;
};

#endif
