/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:18:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/04 16:06:53 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        // Create an Intern
        Intern intern;

        // Test making a ShrubberyCreationForm
        Form* shrubberyForm = intern.makeForm("ShrubberyCreationForm", "Garden");
        shrubberyForm->beSigned(Bureaucrat("John Doe", 20));
        shrubberyForm->execute(Bureaucrat("John Doe", 20));

        // Test making a RobotomyRequestForm
        Form* robotomyForm = intern.makeForm("RobotomyRequestForm", "Target");
        robotomyForm->beSigned(Bureaucrat("Jane Doe", 30));
        robotomyForm->execute(Bureaucrat("Jane Doe", 30));

        // Test making a PresidentialPardonForm
        Form* pardonForm = intern.makeForm("PresidentialPardonForm", "Ford Prefect");
        pardonForm->beSigned(Bureaucrat("Zaphod Beeblebrox", 10));
        pardonForm->execute(Bureaucrat("Zaphod Beeblebrox", 10));

        // Try making an unknown form
        Form* unknownForm = intern.makeForm("UnknownForm", "UnknownTarget");  // Should throw UnknownNameException
		unknownForm->beSigned(Bureaucrat("Zort", 10));

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
