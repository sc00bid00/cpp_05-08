/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:06:53 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 14:56:46 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* === EXCEPTIONS === */

void	Bureaucrat::_testBureaucrat(void) {
	if (this->_bureaucratGrade < 1)
		throw GradeTooHighException();
	if (this->_bureaucratGrade > 150)
		throw GradeTooLowException();
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat : Grade is too high ! ");
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat : Grade is too low ! ");
}

/* === CANONICAL IMPLEMENTATION === */

Bureaucrat::Bureaucrat(std::string name, int grade) : _bureaucratName(name), _bureaucratGrade(grade) {
	if (VERBOSE)
		std::cout << BBLUE << "Bureaucrat default constructor called" << RESET << std::endl;
	this->_testBureaucrat();
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : _bureaucratName(src._bureaucratName), _bureaucratGrade(src._bureaucratGrade) {
	if (VERBOSE)
		std::cout << BBLUE << "Bureaucrat copy constructor called" << RESET << std::endl;
	this->_testBureaucrat();
}

Bureaucrat::~Bureaucrat(void){
	if (VERBOSE)
		std::cout << BBLUE << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (this != &rhs)
		this->_bureaucratGrade = rhs._bureaucratGrade;
	return *this;
}

/* === GETTER === */

std::string const	Bureaucrat::getBureaucratName(void) const {
	return this->_bureaucratName;
}

int		Bureaucrat::getBureaucratGrade(void) const {
	return this->_bureaucratGrade;
}

/* === FUNCTIONS === */

void	Bureaucrat::incrementGrade(void) {
	try {
		if (this->_bureaucratGrade > 0)
			this->_bureaucratGrade--;
		this->_testBureaucrat();
	}
	catch (std::exception& e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void) {
		try {
			this->_bureaucratGrade++;
		this->_testBureaucrat();
	}
	catch (std::exception& e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& AForm) const {
	if (AForm.getSigned() && this->getBureaucratGrade() <= AForm.getGradeToSign())
		std::cout << BGREEN << this->getBureaucratName() << " signed " << AForm.getFormName() << RESET << std::endl;
	else
		std::cout << BRED << this->getBureaucratName() << " couldn't sign " << AForm.getFormName() << " because it requires grade " << AForm.getGradeToSign() << ", " << this->getBureaucratName() << " has grade " << this->getBureaucratGrade() << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) {
	form.execute(*this);
	std::cout << BYELLOW << this->_bureaucratName << " executed " << form.getFormName() << RESET << std::endl;
}

/* === OPERATOR === */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
	o << b.getBureaucratName() << ", bureaucrat grade " << b.getBureaucratGrade();
	return o;
}
