/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:20:55 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/12 19:07:08 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <time.h>
# include <exception>
# include "Colors.hpp"
# define ERR_IDENTIFY "No known type identified !"

class	Base {
	public:
		virtual	~Base(void);
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& ptr);
