/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:11:42 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/08 10:25:01 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)	{
	try {
		/* TEST 1 : Shrubbery form create, sign and execute OK */
		Intern	someIntern;
		AForm*	rrf;
		Bureaucrat	foo("Foo", 137);
		rrf = someIntern.makeForm("shrubbery creation", "Office");
		rrf->beSigned(foo);
		foo.signForm(*rrf);
		foo.executeForm(*rrf);
		delete rrf;

		// /* TEST 2 : Robotomy form create, sign and execute OK */
		// Intern	someIntern;
		// AForm*	rrf;
		// Bureaucrat	bar("Bar", 45);
		// rrf = someIntern.makeForm("robotomy request", "Office");
		// rrf->beSigned(bar);
		// bar.signForm(*rrf);
		// bar.executeForm(*rrf);
		// delete rrf;

		// /* TEST 3 : Presidential form create, sign and execute OK */
		// Intern	someIntern;
		// AForm*	rrf;
		// Bureaucrat	foobar("Foobar", 5);
		// rrf = someIntern.makeForm("presidential pardon", "Office");
		// rrf->beSigned(foobar);
		// foobar.signForm(*rrf);
		// foobar.executeForm(*rrf);
		// delete rrf;

		// /* TEST 4 : Unexisting form creation attempt KO */
		// Intern	someIntern;
		// AForm*	rrf;
		// rrf = someIntern.makeForm("some unexisting form", "Zaphod");
		// delete rrf;
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
