/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:39:52 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/14 15:41:31 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.hpp"
#include "main.hpp"

Fixed	parse_num(std::string str, int &pos)
{
	Fixed	n;
	float	result;

	while (str.at(pos) == ' ')
		pos++;
	if (str.at(pos) == '(')
	{
		n = parse_add(str, ++pos);
		if (str.at(pos) == ')')
			pos++;
		return (n);
	}
	std::stringstream strs(str.substr(pos));
	strs >> result;
	pos += strs.tellg();
	return (Fixed(result));
}

Fixed	parse_add(std::string str, int &pos)
{
	Fixed	n;
	Fixed	n2;
	char	op;

	n = parse_mul(str, pos);
	while ((size_t)pos < str.size())
	{
		while (str.at(pos) == ' ')
			pos++;
		op = str.at(pos);
		if (op != '+' && op != '-')
			return (n);
		n2 = parse_mul(str, ++pos);
		if (op == '+')
			n = n + n2;
		else
			n = n - n2;
	}
	return (n);
}

Fixed	parse_mul(std::string str, int &pos)
{
	Fixed	n;
	Fixed	n2;
	char	op;

	n = parse_num(str, pos);
	while ((size_t)pos < str.size())
	{
		while (str.at(pos) == ' ')
			pos++;
		op = str.at(pos);
		if (op != '/' && op != '*')
			return (n);
		n2 = parse_num(str, ++pos);
		if (op == '*')
			n = n * n2;
		else if (op == '/')
			n = n / n2;
	}
	return (n);
}

int		main(int argc, char **argv)
{
	int		pos;

	if (argc <= 1)
	{
		std::cout << "Missing argument: " << argv[0] << " (expression)" << std::endl;
		return (0);
	}
	pos = 0;
	std::cout << parse_add(argv[1], pos) << std::endl;
	return (0);
}
