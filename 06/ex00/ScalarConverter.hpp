/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:52:11 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 13:05:46 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>
# include <math.h>
# include <iomanip>
# include "Colors.hpp"

# define ERR_CONVERTIBLE	"impossible"
# define ERR_DISPLAYABLE	"Non displayable"
# define ERR_ARGNUM			"Wrong number of arguments"
# define PRECISION		15

class	ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter(void);
		ScalarConverter& operator=(ScalarConverter const& rhs);

		static void	convert(std::string str);
};
