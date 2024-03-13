/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:30:25 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/13 14:00:40 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#define RESET "\033[39m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

template <typename T>
class MutantStack: public std::stack<T>{
	public:
		MutantStack(){}
		MutantStack(const MutantStack &copy){
		*this = copy;}
		virtual ~MutantStack(){}
		MutantStack &operator=(const MutantStack &rhs){
			std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void) {return std::stack<T>::c.begin();}
		iterator end(void){return std::stack<T>::c.end();}


};


#endif
