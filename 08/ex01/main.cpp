/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:55:00 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/26 11:22:05 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	populateRandomVector(std::vector<int>&	vector) {
	std::vector<int>::iterator	it;
	for (it = vector.begin(); it != vector.end(); ++it)
		*it = rand() %RDN_MAGNITUDE;
}

int	main(void) {
	srand(time(NULL));
	{
		std::cout << BYELLOW << "Test #1" << RESET << std::endl;
		Span	container(5);

		container.addNumber(5000);
		container.addNumber(10);
		container.addNumber(420);
		container.addNumber(1);
		container.addNumber(1042);
		std::cout << container.shortestSpan() << std::endl;
		std::cout << container.longestSpan() << std::endl;
		std::cout << BYELLOW << "Test #2" << RESET << std::endl;
		container.addNumber(18000); // full container exception
	}
	{
		std::cout << BYELLOW << "Test #3" << RESET << std::endl;
		Span	container(5);

		container.addNumber(20);
		std::cout << container.shortestSpan() << std::endl; // empty container exception
		std::cout << container.longestSpan() << std::endl; // empty container exception

	}
	{
		std::cout << BYELLOW << "Test #4" << RESET << std::endl;
		Span	container(2);

		container.addNumber(42);
		container.addNumber(21);
		std::cout << container.shortestSpan() << std::endl;
		std::cout << container.longestSpan() << std::endl;
	}
	{
		std::cout << BYELLOW << "Test #5" << RESET << std::endl;
		std::vector<int>	sourceVector(100000);
		std::cout << BYELLOW << "Source vector random data"<< RESET << std::endl;
		populateRandomVector(sourceVector);
		std::cout << BPURPLE << "Min : " << *std::min_element(sourceVector.begin(), sourceVector.end());
		std::cout << "  Max : " << *std::max_element(sourceVector.begin(), sourceVector.end());
		std::cout << "  Size : " << sourceVector.size() << RESET << std::endl;
		Span	container(150000);
		container.addInBulk(sourceVector);
		std::cout << container.shortestSpan() << std::endl;
		std::cout << container.longestSpan() << std::endl;
		std::cout << container << std::endl;
	}
	{
		Span	container(3);

		std::cout << BYELLOW << "Test #6" << RESET << std::endl;
		std::cout << BYELLOW << "Original container"<< RESET << std::endl;
		container.addNumber(2);
		container.addNumber(42);
		container.addNumber(4);
		std::cout << container.shortestSpan() << std::endl;
		std::cout << container.longestSpan() << std::endl;
		std::cout << container << std::endl;
		std::cout << BYELLOW << "Copy container"<< RESET << std::endl;
		Span	copyContainer(container);
		std::cout << copyContainer.shortestSpan() << std::endl;
		std::cout << copyContainer.longestSpan() << std::endl;
		std::cout << copyContainer << std::endl;
		std::cout << BYELLOW << "Assigned container"<< RESET << std::endl;
		Span	assignedContainer = container;
		std::cout << assignedContainer.shortestSpan() << std::endl;
		std::cout << assignedContainer.longestSpan() << std::endl;
		std::cout << assignedContainer << std::endl;
	}
	return 0;
}
