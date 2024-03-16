/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:03 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/15 23:23:17 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string tokens): tokens(tokens), w_count(0)
{
	word_count(tokens);
}


RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->tokens = rhs.tokens;
		this->w_count = rhs.w_count;
	}
	return *this;
}

RPN::~RPN(){}


void RPN::word_count(std::string tokens)
{
	std::stringstream ss(tokens);
	std::string word;

	while (ss >> word)
		this->w_count++;
}

bool RPN::Validate(std::string *arr)
{
	std::stringstream ss(tokens);
	std::string word;


	for (int i = 0; i < w_count; i++)
	{
		ss >> arr[i];
		if (arr[i].length() != 1)
		{
			std::cerr << RED << "ERROR: The token must be less than 10" << RESET << std::endl;
			return (false);
		}
		else if (!std::isdigit(arr[i][0]) && arr[i][0] != '+' && arr[i][0] != '-' && arr[i][0] != '*' && arr[i][0] != '/')
		{
			std::cerr << RED << "ERROR: The token must be digits or operators '+ - / *'" << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}


bool RPN::ReversePolishNotation(std::string *arr){

	int i = 0;
	char sign;

	while (i < this->w_count)
	{
		if (std::isdigit(arr[i][0]))
		{
			operand_stack.push(std::stod(arr[i]));
		}
		else if (!isdigit(arr[i][0]) && operand_stack.size() < 2)
		{
			std::cout << RED << "ERROR: first 2 digits must be operands" << RESET << std::endl;
			return (false);
		}
		else if (!isdigit(arr[i][0]))
			operator_stack.push(arr[i][0]);

		if (operator_stack.size() >= 1 && operand_stack.size() >= 2)
		{

			sign = operator_stack.top();
			operator_stack.pop();
			second = operand_stack.top();
			operand_stack.pop();
			first = operand_stack.top();
			operand_stack.pop();

			switch(sign)
			{
				case '+':
					operand_stack.push(first + second);
					break;
				case '-':
					operand_stack.push(first - second);
					break;
				case '*':
					operand_stack.push(first * second);
					break;
				case '/':
					operand_stack.push(first / second);
					break;
			}
		}
		i++;
	}
	return (true);
}
