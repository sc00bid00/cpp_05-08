/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:16:43 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/07 17:33:24 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H
# include <string>
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(RobotomyRequestForm const&);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(RobotomyRequestForm const&);

		virtual void			execute(Bureaucrat const& exceutor) const;
};

#endif
