/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:52:44 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/11 16:03:39 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::m_bits = 8;


// CONSTRUCTORS ================================================================

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	m_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	m_value = value << Fixed::m_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	m_value = (int)roundf(value * (1 << Fixed::m_bits));
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

// OPERATORS ===================================================================

Fixed&	Fixed::operator = (const Fixed& copy)
{
	std::cout << "Assignation operator called" << std::endl;
	m_value = copy.getRawBits();
	return *this;
}

std::ostream &operator << (std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

// MEMBERS ======================================================================

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->m_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->m_value = raw;
}

int		Fixed::toInt(void) const
{
	return (m_value >> Fixed::m_bits);
}

float	Fixed::toFloat(void) const
{
	return (m_value / (float)(1 << Fixed::m_bits));
}
