/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:59:20 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/13 10:45:27 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_HPP
# define EX00_HPP

#include <string>
#include <iomanip>
#include <iostream>

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
		int _fixedPointValue; //stores the fixed-point nb value
		static const int _fractionalBits = 8; //stores the nb of fractional bits
		
	public:
		Fixed(); //constructor
		Fixed(const Fixed& src); //copy constructor - creates new instance; src is the Fixed object to copy from
		Fixed& operator = (const Fixed& otherFixed); //copy assignment operator - updates current instance
		~Fixed(); //destructor

		int getRawBits() const; // returns the raw value of the fixed point value
		void setRawBits(int const raw); //sets the raw value of the fixed-point number
};

#endif