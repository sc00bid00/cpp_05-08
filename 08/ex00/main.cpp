/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:36 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 11:01:54 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "populateContainer.hpp"
#include "Colors.hpp"



int	main(void) {
	srand(time(NULL));
	/* test case list */
	std::cout << BYELLOW << TXT_LIST << CONTAINER_SIZE << ", target integer : " << TARGET_INTEGER << RESET << std::endl;
	std::list<int>		myList;
	populateContainer(myList, CONTAINER_SIZE);
	easyfind(myList, TARGET_INTEGER);

	/* test case vector */
	std::cout << BYELLOW << TXT_VECTOR << CONTAINER_SIZE << ", target integer : " << TARGET_INTEGER << RESET << std::endl;
	std::vector<int>	myVector;
	populateContainer(myVector, CONTAINER_SIZE);
	easyfind(myVector, TARGET_INTEGER);

	/* test case deque */
	std::cout << BYELLOW << TXT_DEQUE << CONTAINER_SIZE << ", target integer : " << TARGET_INTEGER << RESET << std::endl;
	std::deque<int>	myDeque;
	populateContainer(myDeque, CONTAINER_SIZE);
	easyfind(myDeque, TARGET_INTEGER);
	return 0;
}
