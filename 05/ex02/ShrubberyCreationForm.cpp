/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:45:53 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 15:49:26 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* === CANONICAL IMPLEMENTATION === */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	if (VERBOSE)
		std::cout << BBLUE << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src._target) {
	if (VERBOSE)
		std::cout << BBLUE << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	if (VERBOSE)
		std::cout << BBLUE << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/* === FUNCTIONS === */

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	this->testExecutable(executor.getBureaucratGrade());
	std::string tree[2] =	{"\n        1\n       111\n      11111\n     1111111\n    111111111\n   11111111111\n  1111111111111\n\
 111111111111111\n11111111111111111\n      |||||\n      |||||\n      |||||\n    %%%%%%%%%\n", "\n        2\n       222\n\
      22222\n     2222222\n    222222222\n   22222222222\n  2222222222222\n 222222222222222\n22222222222222222\n      |||||\n\
      |||||\n      |||||\n    %%%%%%%%%\n"};
	std::string	fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (file.is_open()) {
		for (int i = 0; i < 5; i++) {
			file << tree[rand() % 2];
		}
		file.close();
	}
	else
		std::cerr << BRED << "Failed to open file " << fileName << RESET << std::endl;
}


