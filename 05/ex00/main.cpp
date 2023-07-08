/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:49:34 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/04 13:50:03 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	admin("Vogon", 42);
		while (admin.getBureaucratGrade() != 0) {
			admin.incrementGrade();
			std::cout << BGREEN << admin << RESET << std::endl;
		}
		while (admin.getBureaucratGrade() != 151) {
			admin.decrementGrade();
			std::cout << BGREEN << admin << RESET << std::endl;
			}

		Bureaucrat	admin_2("Vogon bis", 154);
		while (admin_2.getBureaucratGrade() != 148) {
			admin_2.incrementGrade();
			std::cout << BGREEN << admin_2 << RESET << std::endl;
		}

		Bureaucrat	admin_3(admin_2);
			std::cout << BGREEN << admin << RESET << std::endl;

		Bureaucrat	admin_4("Vogon ter", -123);
			std::cout << BGREEN << admin_4 << RESET << std::endl;
		admin_4.incrementGrade();
			std::cout << BGREEN << admin_4 << RESET << std::endl;

		Bureaucrat	admin_5(admin_4);
		std::cout << BGREEN << admin_5 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
