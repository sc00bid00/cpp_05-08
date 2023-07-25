/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:36:54 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 11:18:32 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include "Macros.hpp"

class	NoMatchesException : public std::exception {
		public:
			virtual char const* what() const throw();
};

char const* NoMatchesException::what() const throw() {
	return NOMATCH_FOUND;
}

template<typename T>
void	easyfind(T& container, int const integer) {
	try {
		typename T::iterator it = std::find(container.begin(), container.end(), integer);
		if (it != container.end()) {
			int index = std::distance(container.begin(), it);
			std::cout << BGREEN << "Match found for integer : " << integer << " at index : " << index << RESET << std::endl;
		}
		else
			throw NoMatchesException();
	}
	catch (std::exception &e)
	{
		std::cout << BRED << e.what() << integer << RESET << std::endl;
	}
}
