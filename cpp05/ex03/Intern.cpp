/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:29:50 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/04 16:06:23 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

Intern::Intern(const Intern& rhs){
	*this = rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << RED << "Intern destructor called" << DEFAULT << std::endl;
}

Form *Intern::makeForm(std::string name, std::string target)
{
    std::auto_ptr<Form> forms[] = {
        std::auto_ptr<Form>(new RobotomyRequestForm(target)),
        std::auto_ptr<Form>(new PresidentialPardonForm(target)),
        std::auto_ptr<Form>(new ShrubberyCreationForm(target))
    };

    for(int i = 0; i < 3; i++)
    {
        if (name == forms[i]->getName())
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i].release();
        }
    }

    throw (Intern::UnknownNameException());
}

