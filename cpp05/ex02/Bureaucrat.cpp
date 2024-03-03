/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:05:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 23:04:40 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("CLOWN"), grade(150){
	std::cout << GRAY << "Default Bureacrat constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){

	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->grade = grade;
		std::cout << GREEN << "Bureaucrat constructor called" << DEFAULT << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << "-----------------------------------" << std::endl;
	std::cout << RED << "Bureaucrat destructor called" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): name(rhs.getName() + "_copy")
{
	std::cout << YELLOW << "Bureaucrat Copy Constructor called to copy " << rhs.getName() <<
	" into " << this->getName() << DEFAULT << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	*this = rhs;
}

// Operator Overloads
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << MAGENTA << "Bureaucrat Assignation operator called" << DEFAULT << std::endl;
	if (this == &rhs)
		return *this;

	this->grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade();
	return (o);
}

// Getters
const std::string Bureaucrat::getName(void)const{
	return this->name;
}

int Bureaucrat::getGrade(void)const{
	return this->grade;
}

// Setters
void	Bureaucrat::setGrade(const int new_grade){
	this->grade = new_grade;
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("Grade too high");
}

// Increment & Decrement grade
void			Bureaucrat::decrementGrade(void){
	std::cout << RED << "Decrementing bureaucrat " << name << "'s grade " << grade << " by 1" << DEFAULT << std::endl;
	if (this->grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->grade++;
}

void			Bureaucrat::incrementGrade(void){
	std::cout << CYAN << "Incrementing bureaucrat " << name << "'s grade " << grade << " by 1" << DEFAULT << std::endl;
	if (this->grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->grade--;
}

void			Bureaucrat::signForm(Form &form){
	return form.beSigned(*this);
}

void			Bureaucrat::executeForm(Form const & form){
	try {
		form.execute(*this);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

}
