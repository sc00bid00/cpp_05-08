/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:47:56 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 17:33:15 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H
# include <string>
# include <iostream>

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm const&);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm const&);

		virtual void			execute(Bureaucrat const& exceutor) const;
};

#endif
