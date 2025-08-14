/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:48 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 16:09:18 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << GRN << "Default constructor called" << RES << std::endl;
}

Fixed::Fixed(const Fixed& src){
	std::cout << GRN << "Copy constructor called" << RES << std::endl;
	*this = src;
}

Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RES << std::endl;
}

//Converts the int to the corresponding fixed-point value. 
Fixed::Fixed(const int i){
	std::cout << GRN << "Int constructor called" << RES << std::endl;
	this->_fixedPointValue = i << this->_fractionalBits; //this->_fixedPointValue = i * 256;
}
//Converts the float to the corresponding fixed-point value.
//roundf takes a float and returns a float rounded to int
Fixed::Fixed(const float f){
	std::cout << GRN << "Float constructor called" << RES << std::endl;
	this->_fixedPointValue = (int)roundf(f * (1 << this->_fractionalBits));
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Fixed& Fixed::operator = (const Fixed& otherFixed){
	std::cout << YEL << "Copy assignment operator called" << RES << std::endl;
	if (this != &otherFixed) //checks for self assignment (a == a;)
		this->_fixedPointValue = otherFixed.getRawBits();
	return (*this);
}

std::ostream& operator << (std::ostream& output, const Fixed& fixednbr){
	output << fixednbr.toFloat();
	return output;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

int Fixed::getRawBits() const{
	//std::cout << BCYA << "getRawBits member function called" << RES << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	//std::cout << BCYA << "setRawBits member function called" << RES << std::endl;
	this->_fixedPointValue = raw;
}

//converts the fixed-point value to an int value.
int	Fixed::toInt() const{
	int i = this->_fixedPointValue >> this->_fractionalBits; // i = this->_fixedPointValue * 256;
	return i;
}

//converts the fixed-point value to a floating-point value.
float Fixed::toFloat() const{
	float f = (float)this->_fixedPointValue / (1 << this->_fractionalBits); // 	f = (float)this->_fixedPointValue / 256.0f;
	return f;
}