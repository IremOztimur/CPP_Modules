/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:41:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/10 19:12:50 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	{
		int intArray[] = {1, 2, 3, 4, 5};
		size_t intArrayLength = sizeof(intArray) / sizeof(int);

		std::cout <<MAGENTA << "-------------[Print Element]------------" << RESET << std::endl;
		std::cout <<  std::endl;
		std::cout << "Iterating over integer array: ";
		iter(intArray, intArrayLength, printElement<int>);
		std::cout << std::endl;
	}

	{
		char charArray[] = {'A', 'B', 'C', '1', '2'};
		size_t charArrayLength = sizeof(charArray) / sizeof(char);

		std::cout <<  std::endl;
		std::cout <<MAGENTA << "--------------[To Lower]----------------" << RESET << std::endl;
		std::cout <<  std::endl;
		std::cout << "Original array: ";
		iter(charArray, charArrayLength, printElement<char>);
		std::cout << std::endl;

		std::cout << "Array after toLower: ";
		iter(charArray, charArrayLength, toLower<char>);
		iter(charArray, charArrayLength, printElement<char>);
		std::cout << std::endl;
	}

	{
		std::string nameArray[] = {"LALALALA", "42", "Oztimur"};
		size_t stringArrayLength = sizeof(nameArray) / sizeof(nameArray[0]);
		std::cout <<  std::endl;
		std::cout <<MAGENTA << "---------------[Rainbow]----------------" << RESET << std::endl;
		std::cout <<  std::endl;
		iter(nameArray, stringArrayLength, rainbow<std::string>);
		std::cout <<  std::endl;
	}

	return 0;
}
