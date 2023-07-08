/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:50:11 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 15:48:48 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* === CANONICAL IMPLEMENTATION === */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	if (VERBOSE)
		std::cout << BBLUE << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src._target) {
	if (VERBOSE)
		std::cout << BBLUE << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	if (VERBOSE)
		std::cout << BBLUE << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/* === FUNCTIONS === */

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	this->testExecutable(executor.getBureaucratGrade());
	std::cout << BGREEN << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}



