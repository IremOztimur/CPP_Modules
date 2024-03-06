/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/06 19:46:16 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string.h>
#include <iostream>
#include <limits>
#include <fstream>

enum s_type{
	NONE,
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL
} ;

// Color Codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;37m"
#define RESET "\033[0m"

class ScalarConverter{
	private:
		char	_char;
		int		_int;
		float	_float;
		double	_double;
		bool	impossible;

		const std::string input;
		s_type	type;


	public:
		// Constructor
		ScalarConverter();
		ScalarConverter(const std::string input);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &rhs);

		// Getters
		std::string getInput(void) const;
		s_type getType(void) const;
		char getChar(void) const;
		int getInt(void) const;
		float getFloat(void) const;
		double getDouble(void) const;

		// Setters
		void setChar(char _char);
		void setInt(int _int);
		void setFloat(float _float);
		void setDouble(double _double);
		void setType(void);


		// Checkers
		bool isImpossible(void);
		bool isLiteral(void) const;
		bool isChar(void) const;
		bool isInt(void) const;
		bool isFloat(void) const;
		bool isDouble(void) const;


		// Printers
		void printChar(void) const;
		void printInt(void) const;
		void printFloat(void) const;
		void printDouble(void) const;

		// Methods
		void convert(void);

		// Exceptions
		class UnknownTypeException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &rhs);

#endif
