/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:20:51 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 09:22:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

// ---- Color Codes ----
# define DEFAULT "\x1b[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

class Form;

class Bureaucrat
{
	public:
		// Orhodox Canonical Form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &rhs);

		// Setters
		void	setGrade(const int new_grade);

		// Getters
		const std::string	getName(void) const;
		int					getGrade(void) const;

		// Increment & Decrement grade
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form &form);

		// Exception Classes:
		class GradeTooHighException: public std::exception{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception{
			virtual const char* what() const throw();
		};

	private:
		const std::string name;
		int				 grade;
};

// << overload
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
