/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:44:56 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 17:33:30 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H
# include "AForm.hpp"
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const&);

		virtual void			execute(Bureaucrat const& exceutor) const;
};

#endif
