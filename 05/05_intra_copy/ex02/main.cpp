/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:11:42 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/08 09:59:53 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)	{
	try {
		/* TEST 1 : Bureaucrat's exec grade OK to sign, KO to execute*/
		Bureaucrat	foo("Foo", 138);	// grade too low to execute
		ShrubberyCreationForm	sForm("home");
		sForm.beSigned(foo);
		foo.signForm(sForm);
		foo.executeForm(sForm);	// creates file with trees

		// /* TEST 2 : shrubberytree excecution OK */
		// Bureaucrat	foo("Foo", 137);
		// ShrubberyCreationForm	sForm("home");
		// sForm.beSigned(foo);
		// foo.signForm(sForm);
		// foo.executeForm(sForm);	// creates file with trees

		// /* TEST 3 : Bureaucrat's robotomyrequest execution OK */
		// Bureaucrat				bar("Bar", 45);
		// RobotomyRequestForm		rForm("google");
		// rForm.beSigned(bar);
		// bar.signForm(rForm);
		// bar.executeForm(rForm);

		// /* TEST 4 : presidentialpardon execution OK */
		// Bureaucrat	foobar("Foobar", 5);
		// PresidentialPardonForm pForm("Evaluator");
		// pForm.beSigned(foobar);
		// foobar.signForm(pForm);
		// foobar.executeForm((pForm));
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
