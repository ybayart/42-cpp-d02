/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:02:37 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/11 17:59:16 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	a = b + c;
	std::cout << "a = b + c" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = c - b;
	std::cout << "a = c - b" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = b * c;
	std::cout << "a = b * c" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = b / c;
	std::cout << "a = b / c" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = 0;
	std::cout << "(a = 0)++" << std::endl;

	std::cout << "a is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;

	a = 0;
	std::cout << "++(a = 0)" << std::endl;

	std::cout << "a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;

	a = 0;
	std::cout << "(a = 0)--" << std::endl;

	std::cout << "a is " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;

	a = 0;
	std::cout << "--(a = 0)" << std::endl;

	std::cout << "a is " << --a << std::endl;
	std::cout << "a is " << a << std::endl;

	std::cout << "min(a, b)" << std::endl;

	std::cout << min(a, b) << std::endl;

	std::cout << "max(a, b)" << std::endl;

	std::cout << max(a, b) << std::endl;

	std::cout << "Fixed::min(a, b)" << std::endl;

	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "Fixed::max(a, b)" << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
