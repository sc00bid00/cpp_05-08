/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:55:00 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 19:06:09 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
		Span	container(100000);

		container.addInBulk();
		std::cout << container.shortestSpan() << std::endl;
		std::cout << container.longestSpan() << std::endl;
		std::cout << container << std::endl;
	}
	return 0;
}
