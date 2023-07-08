/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:11:42 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/08 09:30:54 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)	{
	try {
		/* TEST 1 : Form ok, Bureaucrat OK */
		Bureaucrat	admin("Vogon", 42);
		Form		form("B-52", 50, 100);
		std::cout << BGREEN << admin << RESET << std::endl;	// Bureaucrat <<
		std::cout << BPURPLE << form << RESET << std::endl;	// Form B52 << (signed : no)
		form.beSigned(admin);
		admin.signForm(form);	// 'Vogon signed' message
		std::cout << BPURPLE << form << RESET << std::endl;	// Form B52 << (signed : yes)

		// /* TEST 2 : Form ok Bureaucrat KO */
		// Bureaucrat	admin("Vogon", 42);
		// Form		form("B-53", 1, 1);
		// std::cout << BPURPLE << form << RESET << std::endl; // Form B53 << (signed : no )
		// form.beSigned(admin);	// Grade too low exception, comment line for following tests


		// /* TEST 3 : Bureaucrat OK, form not signed yet */
		// Bureaucrat	admin("Hermes", 1);
		// Form		form("B-53", 1, 1);
		// admin.signForm(form);	// Hermes signed message
		// std::cout << BPURPLE << form << RESET << std::endl;	// Form B53 << (signed : yes)

		// /* TEST 4 - 7 : Forms NOK */
		// Form	form_3("B-54", 151, 1);	// Form KO, grade too low
		// Form	form_4("B-55", 0, 1);	// Form KO, grade too high
		// Form	form_5("B-56", 1, 151);	// Form KO, grade too low
		// Form	form_6("B-57", 1, 0);	// Form KO, grade too high
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
