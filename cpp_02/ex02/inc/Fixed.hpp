/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:02:04 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:59 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_HPP
# define EX02_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Fixed{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int i);
		Fixed(const float f);
		
		Fixed& 	operator = (const Fixed& otherFixed);
		Fixed	operator + (const Fixed& otherFixed) const;
		Fixed	operator - (const Fixed& otherFixed) const;
		Fixed	operator * (const Fixed& otherFixed) const;
		Fixed	operator / (const Fixed& otherFixed) const;
		
		Fixed&	operator ++ (); //pre increment
		Fixed	operator ++ (int); //post increment
		Fixed&	operator -- (); //pre decrement
		Fixed	operator -- (int); //post decrement

		bool	operator > (const Fixed& otherFixed) const;
		bool	operator < (const Fixed& otherFixed) const;
		bool	operator >= (const Fixed& otherFixed) const;
		bool	operator <= (const Fixed& otherFixed) const;
		bool	operator == (const Fixed& otherFixed) const;
		bool	operator != (const Fixed& otherFixed) const;
		
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		int		toInt() const;
		float	toFloat() const;
		
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream operator << (std::ostream& output, Fixed& fixedNbr);

#endif