/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:57 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/15 23:04:58 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **av)
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./ex01 \"<RPN expression>\"" << RESET << std::endl;
		return 1;
	}

	RPN rpn(av[1]);
	std::string arr[rpn.w_count];

	if (!rpn.Validate(arr))
		return EXIT_FAILURE;

	if (rpn.ReversePolishNotation(arr))
	{
		std::cout << "Result: " << rpn.operand_stack.top() << std::endl;
		return EXIT_SUCCESS;
	}
	else
	{
		std::cerr << RED << "ERROR: The expression is not valid" << RESET << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
