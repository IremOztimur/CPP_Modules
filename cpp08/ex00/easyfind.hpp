/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:51:06 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 16:38:40 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <set>

// Color Codes
#define RESET "\033[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

template <typename T>
int	easyfind(T &container, int value){
	typename T::iterator iter = std::find(container.begin(), container.end(), value);

	if (iter == container.end())
		throw (std::runtime_error("Value not found"));

	return *iter;
}

#endif
