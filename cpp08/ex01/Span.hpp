/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:49:14 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 22:28:26 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

// Color Codes
#define RESET "\033[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

class Span{
	private:
		unsigned int N;
		std::vector<int> contents;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &rhs);

		void addNumber(int number);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int size(void) const;
		const std::vector<int> &getContents(void) const;
		void printContents(void) const;

		// Exception Classes
		class FullContainerException : public std::exception {
			virtual const char *what() const throw() {
				return "Container is full!";
			}
		};
		class NotEnoughNumbersException : public std::exception {
			virtual const char *what() const throw() {
				return "Not enough numbers to calculate span!";
			}
		};

};

#endif
