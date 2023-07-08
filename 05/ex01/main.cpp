/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:11:42 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/04 15:06:24 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)	{
	try {
		Bureaucrat	admin("Vogon", 42);
		Form		form("B-52", 50, 100);
		std::cout << BGREEN << admin << RESET << std::endl;
		std::cout << BPURPLE << form << RESET << std::endl;
		form.beSigned(admin);
		admin.signForm(form);
		std::cout << BPURPLE << form << RESET << std::endl;

		Form		form_2("B-53", 1, 1);
		std::cout << BPURPLE << form_2 << RESET << std::endl;
		form_2.beSigned(admin);
		// std::cout << BPURPLE << form_2 << RESET << std::endl;
		// admin.signForm(form_2);

		// Form		form_3("B-54", 151, 1);
		// Form		form_4("B-55", 0, 1);
		// Form		form_5("B-56", 1, 151);
		// Form		form_6("B-57", 1, 0);
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
