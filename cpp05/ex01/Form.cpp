/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:05:12 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 17:34:44 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(): name("Default"), gradeToSign(150), gradeToExecute(150), isSigned(0){
	std::cout << GRAY << "A Default " << this->getName() << " has been constructed " << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(0){
	std::cout << GREEN << "Form Constructor called for " << this->getName() << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	if (this->getGradeToExecute() > 150 || this->getGradeToExecute() > 150)
		throw (GradeTooLowException());
	else if (this->getGradeToExecute() < 1 || this->getGradeToExecute() < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &rhs): name(rhs.getName() + "_copy"), gradeToSign(rhs.getGradeToSign()), gradeToExecute(rhs.getGradeToExecute()) , isSigned(0)
{
	std::cout << YELLOW << "Form Copy Constructor called to copy " << rhs.getName() <<
	" into " << this->getName() << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	*this = rhs;
}

// Operator Overloads
Form &Form::operator=(const Form &rhs)
{
	std::cout << MAGENTA << "Form Assignation operator called" << DEFAULT << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}


Form::~Form(){
	std::cout << "-----------------------------------" << std::endl;
	std::cout << RED << "Form destructor called" << DEFAULT << std::endl;
}

// Getters
std::string	Form::getName(void) const{
	return (this->name);
}

bool		Form::getSigned(void) const{
	return (this->isSigned);
}

int			Form::getGradeToSign(void) const{
	return (this->gradeToSign);
}

int			Form::getGradeToExecute(void) const{
	return (this->gradeToExecute);
}

// Exceptions
const char *Form::GradeTooHighException::what(void) const throw(){
		return ("The grade is too high");
}

const char *Form::GradeTooLowException::what(void) const throw(){
		return ("The grade is too low");
}

void		Form::beSigned(const Bureaucrat &bureaucrat){
	if ((int)bureaucrat.getGrade() > this->getGradeToSign())
	{
		throw (GradeTooLowException());
	}
	else if (this->getSigned() == 0)
	{
		this->isSigned = true;
		std::cout << MAGENTA << this->getName() << " Form was signed by " << bureaucrat.getName() << DEFAULT << std::endl;
	}
	else
		std::cout << YELLOW << this->getName() << " Form is already signed" << DEFAULT << std::endl;
}


std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form " << rhs.getName() << " having a gradeToSign " << rhs.getGradeToSign() << " and a gradeToExecute "
	<< rhs.getGradeToExecute() << " with isSigned equal to " << rhs.getSigned();
	return (o);
}
