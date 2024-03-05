/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:31:34 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 16:18:42 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &other);
		Dog &operator=(Dog const &rhs);

		void makeSound() const;
		void	setIdea(size_t, std::string);
		std::string getIdea(size_t) const;
	private:
		Brain *brain;
};
