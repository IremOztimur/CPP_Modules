/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:13 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 23:46:53 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Required grades: sign 72, exec 45

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs): Form(rhs), target(rhs.target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &rhs){
	(void)rhs;
	return *this;
}

std::string getRandomRobotNoise() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::string robotNoises[] = {"BZZZZZT!\n", "ZAP-ZAP!\n", "DING-DONG!\n", "WHIZZLE-POP!\n", "CLANKITY-CLANK!\n"};

	int randomIndex = std::rand() % (sizeof(robotNoises) / sizeof(robotNoises[0]));

	return robotNoises[randomIndex];
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
	{
		if (std::rand() % 2)
			std::cout << getRandomRobotNoise() << target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed! " << target << " is still alive." << std::endl;
	}
}
