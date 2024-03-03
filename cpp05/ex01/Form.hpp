/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:48:44 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 15:29:19 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string name;
		const int		gradeToSign;
		const int		gradeToExecute;
		bool			isSigned;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(Form const &rhs);
		Form &operator=(Form const &rhs);

		// Getters
		std::string getName(void) const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat &bureaucrat);

		// Exception Classes:
		class GradeTooHighException: public std::exception{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
