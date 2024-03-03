/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:18:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 18:05:24 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
{
	try {
        // Test Bureaucrat
        Bureaucrat bureaucrat("Irem Oztimur", 40);
        std::cout << bureaucrat << std::endl;

        // Test Form
        Form form("Example", 50, 75);
        std::cout << form << std::endl;

        // Sign the form using Bureaucrat's signForm method
        bureaucrat.signForm(form);

        // Try signing the form again (should print a message that it's already signed)
        bureaucrat.signForm(form);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

    try {
        // Test Bureaucrat
        Bureaucrat bureaucrat("Irem Oztimur", 70);
        std::cout << bureaucrat << std::endl;

        // Test Form
        Form form("Example", 50, 75);
        std::cout << form << std::endl;

        // Sign the form using Bureaucrat's signForm method
        bureaucrat.signForm(form);

        // Try signing the form again (should print a message that it's already signed)
        bureaucrat.signForm(form);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return 0;
}
