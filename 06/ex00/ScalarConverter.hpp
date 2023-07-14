/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:52:11 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/14 16:58:48 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <exception>
# include <limits>
# include <string>
# include <string.h>
# include <cmath>
# include "Colors.hpp"

# define ERR_NARG	"Requires 1 argument"
# define ERR_DISP	BYELLOW << "Not displayable" << RESET
# define ERR_CONV	"Impossible"

# define M_CHAR		"char   : "
# define M_INT		"int    : "
# define M_FLOAT	"float  : "
# define M_DOUBLE	"double : "

enum isType {
	IS_ELSE,
	IS_DOUBLE,
	IS_FLOAT,
	IS_INT,
	IS_CHAR,
	IS_SPECIAL,
	IS_ZERO
};

enum charType {
	IS_NOCHAR,
	IS_NODISP,
	IS_DISP
};

class	ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter(void);
		ScalarConverter& operator=(ScalarConverter const& rhs);
	public:
		static void	convert(std::string literal);
};

