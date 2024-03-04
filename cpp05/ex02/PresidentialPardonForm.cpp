/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:47:08 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/04 09:58:02 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Required grades: sign 25, exec 5
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("PresidentialPardonForm", 72, 45), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs): Form(rhs), target(rhs.target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &rhs){
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor)const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
		std::cout << CYAN << target << " has been pardoned by Zaphod Beeblebrox" << DEFAULT << std::endl;
}
