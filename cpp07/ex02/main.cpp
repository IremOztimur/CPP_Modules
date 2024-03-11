/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:50:00 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/11 17:40:59 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

#define MAX_VAL 750

int main() {
	{
		std::cout << "Creating an array using default constructor:" << std::endl;
		Array<int> intArrayDefault;
		std::cout << "Size of the array: " << intArrayDefault.size() << std::endl;

		std::cout << "\nCreating an array with a parameterized constructor:" << std::endl;
		Array<double> doubleArray(5);
		std::cout << "Size of the array: " << doubleArray.size() << std::endl;

		std::cout << "\nCreating a copy of the array:" << std::endl;
		Array<double> doubleArrayCopy(doubleArray);
		std::cout << "Size of the copied array: " << doubleArrayCopy.size() << std::endl;

		std::cout << "\nAssigning one array to another:" << std::endl;
		Array<double> doubleArrayAssign;
		doubleArrayAssign = doubleArray;
		std::cout << "Size of the assigned array: " << doubleArrayAssign.size() << std::endl;

		std::cout << "\nAccessing elements of the array:" << std::endl;
		try {
			doubleArray[2];

			// Accessing an out-of-range index to trigger the exception
			doubleArray[10];
		} catch (const Array<double>::InvalidIndexException& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{

		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}

	{
		Array<float> numbers(20);

		for (int i = 0; i < 20; i++)
		{
			numbers[i] = i;
		}
		for (int i = 0; i < 20; i++)
		{
			std::cout << numbers[i] << " ";
		}
	}

	return 0;
}
