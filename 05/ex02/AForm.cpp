/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:26 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 11:26:30 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

/* === EXCEPTIONS === */

char const*	AForm::GradeTooHighException::what() const throw() {
	return ("AForm : Grade is too high ! ");
}

char const*	AForm::GradeTooLowException::what() const throw() {
	return ("AForm : Grade is too low ! ");
}

char const*	AForm::FormUnsignedException::what() const throw() {
	return ("Unsigned forms cannot be executed ! ");
}

char const*	AForm::TooLowForExecutionException::what() const throw() {
	return ("Bureaucrat's grade too low to execute ! ");
}

/* === CANONICAL IMPLEMENATION === */

AForm::AForm(std::string name, int const gradeToSign, int const gradeToExecute) : _formName(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (VERBOSE)
		std::cout << BBLUE << "AForm default constructor called" << RESET << std::endl;
	this->_testForm();
}

AForm::AForm(AForm const& src) : _formName(src._formName), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	if (VERBOSE)
		std::cout << BBLUE << "AForm copy constructor called" << RESET << std::endl;
	this->_testForm();
}

AForm::~AForm(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Fom destructor called" << RESET << std::endl;
}

AForm&	AForm::operator=(AForm const& rhs) {
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

/* === GETTERS === */

std::string const	AForm::getFormName(void) const {
	return this->_formName;
}

bool				AForm::getSigned(void) const {
	return this->_signed;
}

int					AForm::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int					AForm::getGradeToExecute(void) const {
	return this->_gradeToExecute;

}

/* === FUNCTIONS === */

void	AForm::_testForm(void) const {
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

void	AForm::beSigned(Bureaucrat b) {
	if (this->_gradeToSign >= b.getBureaucratGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::testExecutable(int bureaucratExecutionGrade) const {
	if (!this->_signed)
		throw FormUnsignedException();
	else if (bureaucratExecutionGrade > this->getGradeToExecute())
		throw TooLowForExecutionException();
}

/* === OPERATORS === */

std::ostream&	operator<<(std::ostream& o, AForm const& AForm) {
	std::string	msg = "no";
	if (AForm.getSigned())
		msg = "yes";
	o << "AForm name : " << AForm.getFormName() << ", grade to sign : " << AForm.getGradeToSign() << ", grade to execute : " << AForm.getGradeToExecute() << ", signed : " << msg;
	return o;
}

