/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:59:20 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 17:00:46 by icunha-t         ###   ########.fr       */
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
		int _fixedPointValue; //int value of FPN (left to the .)
		static const int _fractionalBits = 8; //nb of bits of fractional value (right to the .)
		
	public:
		Fixed(); //constructor
		Fixed(const Fixed& src); //copy constructor
		
		Fixed& operator = (const Fixed& otherFixed); //copy assignment operator
		
		~Fixed(); //destructor

		int getRawBits() const; //returns the value of _fixedPointValue
		void setRawBits(int const raw); //allows changing the value of _fixedPointValue
};

#endif