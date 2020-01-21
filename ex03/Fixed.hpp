/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:35:29 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/14 16:37:08 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <sstream>
# include <iostream>
# include <cmath>

class	Fixed
{
	private:
	int					m_value;
	const static int	m_bits;

	public:

	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed & copy);
	~Fixed(void);

	Fixed&	operator = (const Fixed& copy);

	bool	operator > (const Fixed& cmp) const;
	bool	operator < (const Fixed& cmp) const;
	bool	operator >= (const Fixed& cmp) const;
	bool	operator <= (const Fixed& cmp) const;
	bool	operator == (const Fixed& cmp) const;
	bool	operator != (const Fixed& cmp) const;

	Fixed	operator + (const Fixed& cmp) const;
	Fixed	operator - (const Fixed& cmp) const;
	Fixed	operator * (const Fixed& cmp) const;
	Fixed	operator / (const Fixed& cmp) const;

	Fixed&	operator ++ (void);
	Fixed	operator ++ (int);
	Fixed&	operator -- (void);
	Fixed	operator -- (int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream &operator << (std::ostream &o, Fixed const &rhs);

Fixed&	min(Fixed& a, Fixed& b);
Fixed&	max(Fixed& a, Fixed& b);

#endif
