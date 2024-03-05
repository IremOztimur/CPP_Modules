/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:44:46 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 16:18:19 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
public:
	Cat();
	~Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &rhs);

	void makeSound() const;
	void	setIdea(size_t, std::string);
	std::string getIdea(size_t) const;
private:
	Brain *brain;
};
