/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:42:00 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 14:49:44 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#ifndef INVENTORY_SIZE
	#define INVENTORY_SIZE 4
#endif

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inventory[INVENTORY_SIZE];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const & other);
		MateriaSource & operator=(MateriaSource const & rhs);
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
