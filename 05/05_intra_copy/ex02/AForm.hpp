/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:15:14 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 11:46:31 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm {
	private:
		std::string	const	_formName;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		void				_testForm() const;

	public:
		class	GradeTooHighException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		class	FormUnsignedException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		class	TooLowForExecutionException : public std::exception {
			public:
				virtual char const*	what() const throw();
		};

		AForm(std::string, int const, int const);
		AForm(AForm const&);
		virtual ~AForm(void);
		AForm&	operator=(AForm const&);

		std::string const	getFormName(void) const;
		bool				getSigned(void) const;
		int 				getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(Bureaucrat);

		void				testExecutable(int) const;
		virtual void		execute(Bureaucrat const& exceutor) const = 0;
};

std::ostream&	operator<<(std::ostream&, AForm const&);

#endif
