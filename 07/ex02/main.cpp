/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:05:48 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 15:06:16 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

int	main(void) {
	{
		srand(time(NULL));
		try {
			std::cout << BYELLOW << "array" << RESET << std::endl;
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
			array[2] = 424242;
			std::cout << array[2] << std::endl;
			std::cout << BYELLOW << "b_array" << RESET << std::endl;
			Array<int>	b_array(array);
			std::cout << "Array size is : " << b_array.size() << std::endl;
			for (int i = 0; i < 3; i++) {
				std::cout << b_array[i] << std::endl;
			}
			b_array[2] = -42;
			std::cout << "array[2] : " << array[2] << " b_array[2] : " << b_array[2] << std::endl;
			std::cout << BYELLOW << "c_array" << RESET << std::endl;
			Array<int>	c_array = b_array;
			std::cout << "Array size is : " << c_array.size() << std::endl;
			for (int i = 0; i < 3; i++) {
				std::cout << c_array[i] << std::endl;
			}
			std::cout << BYELLOW << "d_array" << RESET << std::endl;
			Array<int>	d_array;	// empty array;
			std::cout << "Array size is : " << d_array.size() << std::endl;
			d_array[0] = 42;	// exception, array is empty;
			for (int i = 0; i < 3; i++) {
				std::cout << d_array[i] << std::endl; // exception, array is empty
			}
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
