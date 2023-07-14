/* ************************************************************************** */
/*                   */
/*              :::  :::::::: */
/* ScalarConverter.cpp        :+:  :+: :+: */
/*             +:+ +:+   +:+  */
/* By: lsordo <lsordo@student.42heilbronn.de>  +#+ +:+  +#+  */
/*            +#+#+#+#+#+ +#+   */
/* Created: 2023/07/13 10:22:06 by lsordo   #+# #+#    */
/* Updated: 2023/07/14 17:02:24 by lsordo   ### ########.fr  */
/*                   */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* === CANONICAL IMPLEMENTATION === */

ScalarConverter::ScalarConverter(void) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter	&	ScalarConverter::operator=(ScalarConverter const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/* === METHOD IMPLEMENTATION === */
bool	isNanf(std::string token) {
	std::string tkn[3] = {"nanf", "+nanf", "-nanf"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isNan(std::string token) {
	std::string tkn[3] = {"nan", "+nan", "-nan"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isInff(std::string token) {
	std::string tkn[3] = {"inff", "+inff", "-inff"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isInf(std::string token) {
	std::string tkn[3] = {"inf", "+inf", "-inf"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isSpecialToken(std::string	s) {
	if (isInf(s) || isInff(s) || isNan(s) || isNanf(s))
		return true;
	return false;
}

bool	isZero(std::string str) {
	int	flag = 0;
	if (str[str.length() - 1] == 'f')
		str.erase(str.length() - 1);
	for (unsigned int i = 0; i < str.length(); i++) {
		if (!flag && str[i] == '.')
			flag |= 1;
		else if (flag && str[i] == '.')
			return false;
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			;
		else if (str[i] != '0')
			return false;
	}
	return true;
}

int	charType(long double ld) {
	if (ld >= 0 && ld <= 255) {
		if (std::isprint(static_cast<char>(ld)))
			return IS_DISP;
		else
			return IS_NODISP;
	}
	return IS_NOCHAR;
}

bool	inDoubleLimits(long double ld) {
	ld = std::abs(ld);
	if (ld <= std::numeric_limits <double>::max() && ld >= std::numeric_limits <double>::min())
		return true;
	return false;
}

bool	inIntLimits(long double ld) {
	if (ld <= std::numeric_limits<int>::max() && ld >= std::numeric_limits<int>::min())
		return true;
	return false;
}

bool	inFloatLimits(long double ld) {
	ld = abs(ld);
	if (ld <= std::numeric_limits <float>::max() && ld >= std::numeric_limits <float>::min())
		return true;
	return false;
}

bool	hasScientific(char *s) {
	while(s && *s) {
		if (*(s++) == 'e')
			return true;
	}
	return false;
}

bool	hasDot(char *s)
{
	while(s && *s) {
		if (*(s++) == '.')
			return true;
	}
	return false;
}

std::string	postFixDouble(char *s) {
	if (!hasScientific(s) && !hasDot(s))
		return ".0";
	double ld = strtod(s, NULL);
	if (ld - static_cast<int>(ld) == 0)
		return ".0";
	return "";
}

std::string	postFixFloat(char *s) {
	if (hasScientific(s))
		return "f";
	if(!hasDot(s))
		return ".0f";
	return "f";
}

int	typeChecker(char* s) {
	char*		lastChar;
	long double	ld = strtold(s, &lastChar);
	if (s && strlen(s) == 1)
		return IS_CHAR;
	if (s && isZero((std::string)s))
		return IS_ZERO;
	if (isSpecialToken((std::string)s))
		return IS_SPECIAL;
	if (!*lastChar && !hasDot(s)) {
		int n = static_cast<int>(ld);
		if (n && inIntLimits(ld))
			return IS_INT;
	}
	if (*lastChar && *lastChar == 'f' && *lastChar == s[strlen(s)- 1]) {
		float	f = static_cast<float>(ld);
		if (f)
			f = abs(f);
		if (f && inFloatLimits(ld))
			return IS_FLOAT;
	}
	if (!*lastChar) {
		double	d = static_cast<double>(ld);
		if (d && inDoubleLimits(ld))
			return IS_DOUBLE;
	}
	if (!*lastChar && s && s[strlen(s) - 1] == '0')
		return IS_DOUBLE;
	return IS_ELSE;
}

void	ScalarConverter::convert(std::string literal) {
	char*	str = const_cast<char*>(literal.c_str());
	long double	ld = strtold(str, NULL);
	switch (typeChecker(str)) {
		case IS_ELSE:
			std::cerr << M_CHAR << ERR_CONV << std::endl;
			std::cerr << M_INT << ERR_CONV << std::endl;
			std::cerr << M_FLOAT << ERR_CONV << std::endl;
			std::cerr << M_DOUBLE << ERR_CONV << std::endl;
			break;
		case IS_DOUBLE:
			if (charType(ld) == IS_DISP)
				std::cout << M_CHAR << static_cast<char>(ld) << std::endl;
			else if (charType(ld) == IS_NODISP)
				std::cerr << M_CHAR << ERR_DISP << std::endl;
			else
				std::cerr << M_CHAR << ERR_CONV << std::endl;
			if (inIntLimits(ld))
				std::cout << M_INT << static_cast<int>(ld) << std::endl;
			else
				std::cerr << M_INT << ERR_CONV << std::endl;
			if (inFloatLimits(ld))
				std::cout << M_FLOAT << static_cast<float>(ld) << postFixFloat(str) << std::endl;
			else
				std::cerr << M_FLOAT << ERR_CONV << std::endl;
			if (inDoubleLimits(ld))
				std::cout << M_DOUBLE << ld << postFixDouble(str) << std::endl;
			else
				std::cerr << M_DOUBLE << ERR_CONV << std::endl;
			break;
		case IS_FLOAT:
			if (charType(ld) == IS_DISP)
				std::cout << M_CHAR << static_cast<char>(ld) << std::endl;
			else if (charType(ld) == IS_NODISP)
				std::cerr << M_CHAR << ERR_DISP << std::endl;
			else
				std::cerr << M_CHAR << ERR_CONV << std::endl;
			if (inIntLimits(ld))
				std::cout << M_INT << static_cast<int>(ld) << std::endl;
			else
				std::cerr << M_INT << ERR_CONV << std::endl;
			std::cout << M_FLOAT << static_cast<float>(ld) << postFixFloat(str) << std::endl;
			std::cout << M_DOUBLE << ld << postFixDouble(str) << std::endl;
			break;
		case IS_INT:
			if (charType(ld) == IS_DISP)
				std::cout << M_CHAR << static_cast<char>(ld) << std::endl;
			else if (charType(ld) == IS_NODISP)
				std::cerr << M_CHAR << ERR_DISP << std::endl;
			else
				std::cerr << M_CHAR << ERR_CONV << std::endl;
			std::cout << M_INT << ld << std::endl;
			std::cout << M_FLOAT << ld << postFixFloat(str) << std::endl;
			std::cout << M_DOUBLE << ld << postFixDouble(str) << std::endl;
			break;
		case IS_CHAR:
			std::cout << M_CHAR << str << std::endl;
			std::cout << M_INT << static_cast<int>(str[0]) << std::endl;
			std::cout << M_FLOAT << static_cast<int>(str[0]) << postFixFloat(str) << std::endl;
			std::cout << M_DOUBLE << static_cast<int>(str[0]) << postFixDouble(str) << std::endl;
			break;
		case IS_ZERO:
			std::cout << M_CHAR << ERR_DISP << std::endl;
			std::cout << M_INT << 0 << std::endl;
			std::cout << M_FLOAT << "0.0f" << std::endl;
			std::cout << M_DOUBLE << "0.0" << std::endl;
			break;
		case IS_SPECIAL:
			std::cerr << M_CHAR << ERR_CONV << std::endl;
			std::cerr << M_INT << ERR_CONV << std::endl;
			if (isInf(str) || isNan(str)) {
				std::cout << M_FLOAT << str << "f" << std::endl;
				std::cout << M_DOUBLE << str << std::endl;
			}
			else {
				std::cout << M_FLOAT << str << std::endl;
				std::cout << M_DOUBLE << ((std::string)str).erase(strlen(str) - 1) << std::endl;
			}
	}
}
