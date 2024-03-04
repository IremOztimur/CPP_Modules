/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:41:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 22:50:27 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//  Required grades: sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm	&rhs) : Form(rhs), target( rhs.target ){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs){
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	if (this->getSigned() == false)
		throw (Form::NotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());

	std::ofstream file(this->getName() + "_shrubbery");
	 if (file.is_open()) {
	file << "        ^\n";
	file << "       ^^^\n";
	file << "      ^^^^^\n";
	file << "     ^^^^^^^\n";
	file << "    ^^^^^^^^^\n";
	file << "   ^^^^^^^^^^^\n";
	file << "  ^^^^^^^^^^^^^\n";
	file << " ^^^^^^^^^^^^^^^\n";
	file << "^^^^^^^^^^^^^^^^^\n";
	file << "        |\n";

	file.close();
	} else{
		 std::cerr << "Unable to open file for writing." << std::endl;
	}
}
