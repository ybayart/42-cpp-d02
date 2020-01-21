/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:52:44 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/11 15:19:14 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::m_bits = 8;

Fixed::Fixed(int value)
{
	std::cout << "Default constructor called" << std::endl;
	m_value = value;
}

Fixed::Fixed(const Fixed & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator = (const Fixed& copy)
{
	std::cout << "Assignation operator called" << std::endl;
	m_value = copy.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->m_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->m_value = raw;
}
