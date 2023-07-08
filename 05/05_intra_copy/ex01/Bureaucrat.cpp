/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:06:53 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/08 09:28:10 by lsordo           ###   ########.fr       */
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
	this->_bureaucratGrade--;
	this->_testBureaucrat();
}

void	Bureaucrat::decrementGrade(void) {
	this->_bureaucratGrade++;
	this->_testBureaucrat();
}

void	Bureaucrat::signForm(Form& form) const {
	if (form.getSigned() && this->getBureaucratGrade() <= form.getGradeToSign())
		std::cout << BGREEN << this->getBureaucratName() << " signed " << form.getFormName() << RESET << std::endl;
	else if (!form.getSigned() && this->getBureaucratGrade() <= form.getGradeToSign())
		std::cout << BYELLOW << this->getBureaucratName() << " can sign " << form.getFormName() << " but still has to do so yet !"  << RESET << std::endl;
	else if (form.getSigned() && this->getBureaucratGrade() > form.getGradeToSign())
		std::cout << BRED << this->getBureaucratName() << " couldn't sign " << form.getFormName() << " because this Form requires grade " << form.getGradeToSign() << ", " << this->getBureaucratName() << " has grade " << this->getBureaucratGrade() << RESET << std::endl;
}

/* === OPERATOR === */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
	o << b.getBureaucratName() << ", bureaucrat grade " << b.getBureaucratGrade();
	return o;
}
