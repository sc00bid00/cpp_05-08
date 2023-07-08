/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:50:57 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 15:49:09 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* === CANONICAL IMPLEMENTATION === */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	if (VERBOSE)
		std::cout << BBLUE << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src._target) {
	if (VERBOSE)
		std::cout << BBLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	if (VERBOSE)
		std::cout << BBLUE << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/* === FUNCTIONS === */

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	this->testExecutable(executor.getBureaucratGrade());
	std::cout << BPURPLE << "Making some drilling noise" << RESET << std::endl;
	if ((rand() % 2) == 0)
		std::cout << BGREEN << this->_target << " has been robotomized successfully ! " << RESET << std::endl;
	else
		std::cout << BRED << "Robotomy failed on " << this->_target << " !" << RESET << std::endl;
}


