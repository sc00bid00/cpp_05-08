/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:26 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/04 15:03:21 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* === EXCEPTIONS === */

void	Form::_testForm(void) {
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

char const*	Form::GradeTooHighException::what() const throw() {
	return ("Form : Grade is too high ! ");
}

char const*	Form::GradeTooLowException::what() const throw() {
	return ("Form : Grade is too low ! ");
}

/* === CANONICAL IMPLEMENATION === */

Form::Form(std::string name, int const gradeToSign, int const gradeToExecute) : _formName(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (VERBOSE)
		std::cout << BBLUE << "Form default constructor called" << RESET << std::endl;
	this->_testForm();
}

Form::Form(Form const& src) : _formName(src._formName), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	if (VERBOSE)
		std::cout << BBLUE << "Form copy constructor called" << RESET << std::endl;
	this->_testForm();
}

Form::~Form(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Fom destructor called" << RESET << std::endl;
}

Form&	Form::operator=(Form const& rhs) {
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

/* === GETTERS === */

std::string const	Form::getFormName(void) const {
	return this->_formName;
}

bool				Form::getSigned(void) const {
	return this->_signed;
}

int					Form::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int					Form::getGradeToExecute(void) const {
	return this->_gradeToExecute;

}

/* === FUNCTIONS === */

void				Form::beSigned(Bureaucrat b) {
	if (this->_gradeToSign >= b.getBureaucratGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/* === OPERATORS === */

std::ostream&	operator<<(std::ostream& o, Form const& form) {
	std::string	msg = "no";
	if (form.getSigned())
		msg = "yes";
	o << "Form name : " << form.getFormName() << ", grade to sign : " << form.getGradeToSign() << ", grade to execute : " << form.getGradeToExecute() << ", signed : " << msg;
	return o;
}

