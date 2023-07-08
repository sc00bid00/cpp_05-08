/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:15:14 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/04 14:38:54 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form {
	private:
		std::string	const	_formName;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		void				_testForm();

	public:
		class	GradeTooHighException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		Form(std::string, int const, int const);
		Form(Form const&);
		~Form(void);
		Form&	operator=(Form const&);

		std::string const	getFormName(void) const;
		bool				getSigned(void) const;
		int 				getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(Bureaucrat);
};

std::ostream&	operator<<(std::ostream&, Form const&);

#endif
