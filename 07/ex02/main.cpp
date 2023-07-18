/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:05:48 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 13:46:13 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

int	main(void) {
	{
		srand(time(NULL));
		try {
			Array<int>	array(3);
			std::cout << "Array size is : " << array.size() << std::endl;
			for (int i = 0; i < 3; i++) {
				int	r = rand() %100;
				array[i] = r;
			}
			for (int i = 0; i < 3; i++) {
				std::cout << array[i] << std::endl;
			}
			std::cout << "Array size is : " << array.size() << std::endl;
			array[3] = 1000;	// should throw an exception
		}
		catch (std::exception &e) {
			std::cerr << BRED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			Array<std::string>	array(3);
			std::cout << "Array size is : " << array.size() << std::endl;
			array[0] = "Hello";
			array[1] = "World";
			array[2] = "!";
			for (int i = 0; i < 3; i++) {
				std::cout << array[i] << std::endl;
			}
			std::cout << "Array size is : " << array.size() << std::endl;
			array[3] = "Ciao";	// should throw an exception
		}
		catch (std::exception &e) {
			std::cerr << BRED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
