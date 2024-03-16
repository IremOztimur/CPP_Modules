/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:13:17 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/16 11:10:12 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <list>
# include <queue>

#define RESET "\033[39m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

bool ValidateAndParse(int argc, char **av, std::list<int> &list, std::deque<int> &deque);

template <typename T>
void insertionSort(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();

	while (it != end) {
		typename T::iterator it2 = it;
		while (it2 != container.begin() && *it2 < *(std::prev(it2))) {
			std::iter_swap(it2, std::prev(it2));
			--it2;
		}
		++it;
	}
}

template <typename T>
void MergeInsertSort(T &container){

	size_t  size = container.size();
	size_t threshold = 60;

	if (size < threshold)
		insertionSort(container);
	else {
		size_t half = size / 2;
		typename T::iterator begin = container.begin();
		typename T::iterator mid = container.begin();
		typename T::iterator end = container.end();
		std::advance(mid, half);

		T left(begin, mid);
		T right(mid, end);

		if (left.size() > 1)
			MergeInsertSort(left);
		if (right.size() > 1)
			MergeInsertSort(right);
		std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
	}
}


#endif
