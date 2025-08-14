/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:48 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 21:16:38 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Fixed::Fixed(): _fixedPointValue(0) {
//	std::cout << GRN << "Default constructor called" << RES << std::endl;
}

Fixed::Fixed(const Fixed& src){
//	std::cout << GRN << "Copy constructor called" << RES << std::endl;
	*this = src;
}

Fixed::~Fixed(){
//	std::cout << RED << "Destructor called" << RES << std::endl;
}

Fixed::Fixed(const int i){
//	std::cout << GRN << "Int constructor called" << RES << std::endl;
	this->_fixedPointValue = i << this->_fractionalBits;
}

Fixed::Fixed(const float f){
//	std::cout << GRN << "Float constructor called" << RES << std::endl;
	this->_fixedPointValue = (int)roundf(f * (1 << this->_fractionalBits));
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Fixed& Fixed::operator = (const Fixed& otherFixed){
//	std::cout << YEL << "Copy assignment operator called" << RES << std::endl;
	if (this != &otherFixed)
		this->_fixedPointValue = otherFixed.getRawBits();
	return (*this);
}

std::ostream& operator << (std::ostream& output, const Fixed& fixedNbr){
	output << fixedNbr.toFloat();
	return output;
}

Fixed	Fixed::operator + (const Fixed& otherFixed) const{
	Fixed newFixed;
	
	newFixed.setRawBits(this->getRawBits() + otherFixed.getRawBits());
	return newFixed;
}

Fixed	Fixed::operator - (const Fixed& otherFixed) const{
	Fixed newFixed;
	
	newFixed.setRawBits(this->getRawBits() - otherFixed.getRawBits());
	return newFixed;
}

Fixed	Fixed::operator * (const Fixed& otherFixed) const{
	Fixed newFixed;
	long long rawNbr = (long long)this->getRawBits() * (long long)otherFixed.getRawBits();
	
	newFixed.setRawBits((int)rawNbr >> this->_fractionalBits);
	return newFixed;
}

Fixed Fixed::operator / (const Fixed& otherFixed) const {
    Fixed newFixed;
	
    long long numerator = ((long long)this->getRawBits() << this->_fractionalBits);
    long long result = numerator / otherFixed.getRawBits();
    newFixed.setRawBits((int)result);
    return newFixed;
}

Fixed&	Fixed::operator ++ (){
	
	this->_fixedPointValue++;	
	return *this;
}

Fixed	Fixed::operator ++ (int){
	Fixed newFixed;
	
	newFixed.setRawBits(this->getRawBits());
	this->_fixedPointValue++;
	return newFixed;
}

Fixed&	Fixed::operator -- (){
	this->_fixedPointValue--;	
	return *this;
}
 
Fixed	Fixed::operator -- (int){
	Fixed newFixed;

	newFixed.setRawBits(this->getRawBits());
	this->_fixedPointValue--;
	return newFixed;
}

bool	Fixed::operator > (const Fixed& otherFixed) const{
	if (this->getRawBits() > otherFixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator < (const Fixed& otherFixed) const{
	if (this->getRawBits() < otherFixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator >= (const Fixed& otherFixed) const{
	if (this->getRawBits() >= otherFixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator <= (const Fixed& otherFixed) const{
	if (this->getRawBits() <= otherFixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator == (const Fixed& otherFixed) const{
	if (this->getRawBits() == otherFixed.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator != (const Fixed& otherFixed) const{
	if (this->getRawBits() != otherFixed.getRawBits())
		return true;
	return false;
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

int	Fixed::toInt() const{
	int i = this->_fixedPointValue >> this->_fractionalBits;
	return i;
}

float Fixed::toFloat() const{
	float f = (float)this->_fixedPointValue / (1 << this->_fractionalBits);
	return f;
}


Fixed& Fixed::min(Fixed& v1, Fixed& v2){
	if (v1 < v2)
		return v1;
	else
		return v2;
}

const Fixed& Fixed::min(const Fixed& v1, const Fixed& v2){
	if (v1 < v2)
		return v1;
	else
		return v2;
}

Fixed& Fixed::max(Fixed& v1, Fixed& v2){
	if (v1 > v2)
		return v1;
	else
		return v2;
}

const Fixed& Fixed::max(const Fixed& v1, const Fixed& v2){
	if (v1 > v2)
		return v1;
	else
		return v2;
}