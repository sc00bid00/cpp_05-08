/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:10:44 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/08 10:22:33 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* === EXCEPTIONS === */

char const*	Intern::UnexistingFormException::what() const throw() {
	return ("Requested form does not exist ! ");
}

/* === CANONICAL IMPLEMENTATION === */

Intern::Intern() {
	if (VERBOSE)
		std::cout << BBLUE << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const& src) {
	*this = src;
	if (VERBOSE)
		std::cout << BBLUE << "Intern copy constructor called" << RESET << std::endl;
}

Intern::~Intern(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Intern destructor called" << RESET << std::endl;
}

Intern&	Intern::operator=(Intern const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}
 /* === FUNCTIONS === */
AForm*	Intern::makeForm(std::string formName, std::string formTarget) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i;
	for (i = 0; i < 3 && formName != forms[i]; i++)
		;
	switch(i) {
		case 0:
			std::cout << BYELLOW << "Intern creates " << formName << RESET << std::endl;
			return(new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << BYELLOW << "Intern creates " << formName << RESET << std::endl;
			return(new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << BYELLOW << "Intern creates " << formName << RESET << std::endl;
			return(new PresidentialPardonForm(formTarget));
		default:
			throw UnexistingFormException();
	}
}
