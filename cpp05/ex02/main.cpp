/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:18:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 23:47:25 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>


int main() {
    try {
        // Create a bureaucrat
        Bureaucrat bureaucrat("John Doe", 80);

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("Garden");

        // Display the bureaucrat and the form
        std::cout << bureaucrat << std::endl;
        std::cout << shrubberyForm << std::endl;

        // Try signing the form
        bureaucrat.signForm(shrubberyForm);

        // Execute the form
        bureaucrat.executeForm(shrubberyForm);

        // Attempt to execute the form with a bureaucrat with a lower grade
        Bureaucrat lowGradeBureaucrat("Lower Grade", 150);
        lowGradeBureaucrat.executeForm(shrubberyForm);  // Should throw GradeTooLowException

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{
    // Create a bureaucrat
    Bureaucrat bureaucrat("John Doe", 41);

    // Create a RobotomyRequestForm
    RobotomyRequestForm robotomyForm("Target");

    try {
        // Try to execute the form with the bureaucrat
        robotomyForm.execute(bureaucrat);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

    return 0;
}
