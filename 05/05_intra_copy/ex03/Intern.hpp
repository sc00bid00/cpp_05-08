/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:36 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 15:27:41 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <string>
# include <iostream>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern{
	public:
		class	UnexistingFormException : public std::exception {
			public:
				virtual char const* what() const throw();
		};
		Intern(void);
		Intern(Intern const&);
		~Intern();

		Intern&	operator=(Intern const&);
		AForm*	makeForm(std::string formName, std::string formTarget);
};

#endif
