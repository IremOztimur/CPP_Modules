/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:48:44 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/03 22:35:09 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
		virtual ~Form();
		Form(Form const &rhs);
		Form &operator=(Form const &rhs);

		// Getters
		std::string getName(void) const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat &bureaucrat);

		// Exception Classes //
		class GradeTooHighException: public std::exception{
			public:
				virtual const char*	what() const throw()  { return "Grade too high"; }
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};

		class NotSignedException: public std::exception{
			public:
				virtual const char *what() const throw() { return "Form not signed"; }
		};

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
