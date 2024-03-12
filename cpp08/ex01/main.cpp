/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:21:23 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 22:36:12 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		try{
				Span sp = Span(6);
				sp.addNumber(5);
				sp.addNumber(3);
				sp.addNumber(17);
				sp.addNumber(9);
				sp.addNumber(11);
				sp.addNumber(8);

				sp.printContents();

				std::cout << std::endl;

				std::cout << MAGENTA << "-----[ Shortest Span ]-----" << RESET << std::endl;
				std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
				std::cout << MAGENTA << "-----[ Longest Span ]-----" << RESET << std::endl;
				std::cout << "Longest span: " << sp.longestSpan() << std::endl;

				std::cout << std::endl;
			}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		try
		{
			Span span(300);
			std::vector<int> vector;

			for (int i = 1000; i < 1100; i++)
				span.addNumber(i);

			for (int i = -500; i < -400; i++) {
				vector.push_back(i);}

			span.fillSpan(vector.begin(), vector.end());


			std::cout << std::endl;
			std::cout << YELLOW << "---[Fill Span test - N=300]---" << RESET << std::endl;
			std::cout << std::endl;

			std::cout << MAGENTA << "-----[ Shortest Span ]-----" << RESET << std::endl;
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << MAGENTA << "-----[ Longest Span ]-----" << RESET << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try {
			std::vector<int> vector;
			Span span(10001);
			std::cout << YELLOW << std::endl << "-----[Minimal pdf test - N=10001]-----" << RESET << std::endl;
			std::cout << std::endl;

			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			std::cout << GRAY << "Adding 10001 numbers to vector" << std::endl;
			for (int i = 0; i < 10001; i++)
				vector.push_back(rand());
			std::cout << GRAY << "Adding 10001 numbers to vector complete" << std::endl;
			std::cout << "Adding vector to span" << std::endl;

			span.fillSpan(vector.begin(), vector.end());

			std::cout << "Adding vector to span complete" << RESET << std::endl;
			std::cout << std::endl;

			//span.printContents();
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
