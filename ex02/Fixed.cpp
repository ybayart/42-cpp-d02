/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:52:44 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/11 18:01:31 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::m_bits = 8;


// CONSTRUCTORS ================================================================

Fixed::Fixed(void)
{
	m_value = 0;
}

Fixed::Fixed(const int value)
{
	m_value = value << Fixed::m_bits;
}

Fixed::Fixed(const float value)
{
	m_value = (int)roundf(value * (1 << Fixed::m_bits));
}

Fixed::Fixed(const Fixed & copy)
{
	this->setRawBits(copy.getRawBits());
}

Fixed::~Fixed(void)
{
}

// OPERATORS ===================================================================

Fixed&	Fixed::operator = (const Fixed& copy)
{
	this->m_value = copy.getRawBits();
	return (*this);
}

std::ostream&	operator << (std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool	Fixed::operator > (const Fixed& cmp) const
{
	return (this->getRawBits() > cmp.getRawBits());
}

bool	Fixed::operator < (const Fixed& cmp) const
{
	return (this->getRawBits() < cmp.getRawBits());
}

bool	Fixed::operator >= (const Fixed& cmp) const
{
	return (this->getRawBits() >= cmp.getRawBits());
}

bool	Fixed::operator <= (const Fixed& cmp) const
{
	return (this->getRawBits() <= cmp.getRawBits());
}

bool	Fixed::operator == (const Fixed& cmp) const
{
	return (this->getRawBits() == cmp.getRawBits());
}

bool	Fixed::operator != (const Fixed& cmp) const
{
	return (this->getRawBits() != cmp.getRawBits());
}

Fixed	Fixed::operator + (const Fixed& cmp) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() + cmp.getRawBits());
	return (ret);
}

Fixed	Fixed::operator - (const Fixed& cmp) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() - cmp.getRawBits());
	return (ret);
}

Fixed	Fixed::operator * (const Fixed& cmp) const
{
	Fixed	ret;

	ret.setRawBits((this->getRawBits() * cmp.getRawBits()) >> Fixed::m_bits);
	return (ret);
}

Fixed	Fixed::operator / (const Fixed& cmp) const
{
	Fixed	ret;

	ret.setRawBits((this->getRawBits() << Fixed::m_bits) / cmp.getRawBits());
	return (ret);
}

Fixed&	Fixed::operator ++ (void)
{
	this->m_value++;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed&	Fixed::operator -- (void)
{
	this->m_value--;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

// MEMBERS ======================================================================

int		Fixed::getRawBits(void) const
{
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

Fixed&	min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
