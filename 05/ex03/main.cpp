/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:11:42 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 16:02:07 by lsordo           ###   ########.fr       */
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
		Bureaucrat	foo("Foo", 137);
		ShrubberyCreationForm	sForm("home");
		Bureaucrat	bar("Bar", 45);
		RobotomyRequestForm		rForm("google");
		Bureaucrat	foobar("Foobar", 5);
		PresidentialPardonForm pForm("Evaluator");
		Intern	someIntern;
		AForm*	rrf;

		sForm.beSigned(foo);
		foo.executeForm(sForm);

		rForm.beSigned(bar);
		bar.executeForm(rForm);

		pForm.beSigned(foobar);
		foobar.executeForm((pForm));

		rrf = someIntern.makeForm("shrubbery creation", "Office");
		rrf->beSigned(foo);
		foo.executeForm(*rrf);
		delete rrf;
		rrf = someIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(bar);
		bar.executeForm(*rrf);
		delete rrf;
		rrf = someIntern.makeForm("presidential pardon", "Evaluator");
		rrf->beSigned(foobar);
		foobar.executeForm(*rrf);
		delete rrf;
		rrf = someIntern.makeForm("some unexisting form", "Zaphod");
		delete rrf;
	}
	catch (std::exception& e) {
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}
