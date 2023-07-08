/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:49:34 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 16:53:25 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		/* TEST 1 : valid Bureaucrat*/
		Bureaucrat	admin("Vogon", 42);
		std::cout << BGREEN << admin << RESET << std::endl;

		// /*TEST 2 : increment grade as possible */
		// Bureaucrat	admin_2("Vogon_2", 5);
		// while (1) {
		// 	admin_2.incrementGrade();
		// 	std::cout << BGREEN << admin_2 << RESET << std::endl;
		// }

		// /*TEST 3 : decrement grade as possible */
		// Bureaucrat	admin_3("Vogon_3", 145);
		// while (1) {
		// 	admin_3.decrementGrade();
		// 	std::cout << BGREEN << admin_3 << RESET << std::endl;
		// }

		// /* TEST 4: copy constructor */
		// Bureaucrat	admin_4(admin);
		// std::cout << BGREEN << admin_4 << RESET << std::endl;

		// /* TEST 4: assignemt op */
		// Bureaucrat	admin_5 = admin;
		// std::cout << BGREEN << admin_5 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
