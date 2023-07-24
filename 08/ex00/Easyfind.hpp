/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:59:34 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/24 18:00:17 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <list>

#include <stdexcept>
#include <iostream>
#include "Colors.hpp"

#define	NOMATCH_FOUND	"No match found for : "
#define MATCH_FOUND		"Match found for : "

class	NoMatchesException : public std::exception {
		public:
			virtual char const* what() const throw();
};

char const* NoMatchesException::what() const throw() {
	return NOMATCH_FOUND;
}

template<typename T>
void	easyfind(T& intContainer, int integer) {
	std::list<int>::const_iterator		it;
	bool								found = false;
	try {
		for (it = intContainer.begin(); it != intContainer.end(); ++it) {
			if (*it == integer) {
				found = true;
				break;
			}
		}
		if (found)
			std::cout << BGREEN << MATCH_FOUND << integer << RESET << std::endl;
		else
			throw NoMatchesException();
	}
	catch (std::exception &e)
	{
		std::cout << BRED << e.what() << integer << RESET << std::endl;
	}
}
