/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:15:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 23:57:43 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Brain.hpp"

int main()
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		const Animal	*zoo[5];
		for (int i = 0; i < 5; i++)
		{
			if (i % 2)
			{
				zoo[i] = new Cat();
				if (zoo[i] == NULL)
				{
					perror("Cat allocation failed");
					std::cerr << "Exiting process now";
					exit(1);
				}
			}
			else
			{
				zoo[i] = new Dog();
				if (zoo[i] == NULL)
				{
					perror("Dog allocation failed");
					std::cerr << "Exiting process now";
					exit(1);
				}
			}
		}
		//Testing
			std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << std::endl;
			std::cout << "Animal _type: " << zoo[i]->getType() << std::endl;
			zoo[i]->makeSound();
			std::cout << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		for (int i = 0; i < 5; i++)
			delete(zoo[i]);
	}

	{
		// Deep Copy Test
		std::cout << std::endl;
		Dog *dog = new Dog();
		dog->brain->setIdea(0, "I am a dog");
		std::cout << dog->brain->getIdea(0) << std::endl;
		Dog *copy_dog = new Dog(*dog);
		dog->brain->setIdea(0, "I am nothing");
		std::cout << "Dog's idea: " << dog->brain->getIdea(0) << std::endl;
		std::cout << "Copy's idea: " << copy_dog->brain->getIdea(0) << std::endl;
		delete dog;

	}
}
