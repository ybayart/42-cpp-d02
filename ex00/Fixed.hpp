/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:35:29 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/11 15:40:03 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
	int					m_value;
	const static int	m_bits;

	public:

	Fixed(int value = 0);
	Fixed(const Fixed & copy);
	~Fixed(void);
	Fixed&	operator = (const Fixed& copy);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

#endif
