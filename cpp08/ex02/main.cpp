/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:43:35 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/13 14:07:18 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << std::endl;
		std::cout << MAGENTA << "----[pdf test - integer stack]-----" << RESET << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << YELLOW << "Integer MutantStack elements: " << RESET;
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	{
		MutantStack<std::string> mutantStack;
		std::cout << std::endl;
		std::cout << MAGENTA << "----[oztimur test - string test]-----" << RESET << std::endl;

		mutantStack.push("Hello");
		mutantStack.push("World");
		mutantStack.push("This");
		mutantStack.push("is");
		mutantStack.push("a");
		mutantStack.push("Test");

		std::cout << "Top: " << mutantStack.top() << std::endl;
		std::cout << "Size: " << mutantStack.size() << std::endl;

		MutantStack<std::string>::iterator it = mutantStack.begin();
		MutantStack<std::string>::iterator itEnd = mutantStack.end();

		std::cout << CYAN << "String MutantStack elements: " << RESET;
		while (it != itEnd) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		// Modify elements in the original stack
		it = mutantStack.begin();
		while (it != mutantStack.end()) {
			*it += " -_-";
			++it;
		}

		// Print modified original stack
		std::cout << GREEN << "Modified MutantStack elements: " << RESET;
		it = mutantStack.begin();
		while (it != mutantStack.end()) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
