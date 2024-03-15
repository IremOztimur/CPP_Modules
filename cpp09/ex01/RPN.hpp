/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:29 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/15 23:11:05 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>


#define RESET "\033[39m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

typedef enum
{
	addition =		'+',
	subtraction =	'-',
	divison =		'/',
	multiplication =	'*',
}			operation;

class RPN
{
	private:
		RPN();
		void word_count(std::string tokens);;

		std::string tokens;
		double first;
		double second;
	public:
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rhs);
		RPN(std::string tokens);


		int 		w_count;
		std::stack<char> operator_stack;
		std::stack<double> operand_stack;

		bool Validate(std::string *arr);
		bool ReversePolishNotation(std::string *arr);

};

#endif
