/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:54:35 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/04 14:43:56 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define BRED		"\e[1;31m"
# define BGREEN		"\e[1;32m"
# define BYELLOW	"\e[1;33m"
# define BBLUE		"\e[1;34m"
# define BPURPLE	"\e[1;35m"
# define BCYAN		"\e[1;36m"
# define BWHITE		"\e[1;37m"
# define RESET		"\e[0m"
# define VERBOSE	false

class	Form;
class	Bureaucrat {
	private:
		std::string const	_bureaucratName;
		int					_bureaucratGrade;
		void				_testBureaucrat();
	public:
		class	GradeTooHighException : public std::exception {
			public:
				virtual char const* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual char const* what() const throw();
		};

		Bureaucrat(std::string, int);
		Bureaucrat(Bureaucrat const&);
		~Bureaucrat(void);
		Bureaucrat& operator=(Bureaucrat const&);

		std::string const	getBureaucratName(void) const;
		int					getBureaucratGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form&) const;
};

std::ostream&	operator<<(std::ostream&, Bureaucrat const&);

#endif
