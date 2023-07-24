/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:36 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/24 17:42:56 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <cstdlib>

void	populateList(std::list<int>& lst, unsigned int size) {
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++) {
		int	r = rand() %10;
		std::cout << r << " ";
		lst.push_back(r);
	}
	std::cout << std::endl;
}

int	main(void) {
	std::list<int>	lst;
	/* populate a list of integers */
	populateList(lst, 5);
	/* call easyfind to look for an integer */
	easyfind(lst, 5);
	return 0;
}
