/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:02:28 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 16:08:02 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
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

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Fixed& Fixed::operator = (const Fixed& otherFixed){
	std::cout << YEL << "Copy assignment operator called" << RES << std::endl;
	if (this != &otherFixed)
		this->_fixedPointValue = otherFixed.getRawBits();
	return (*this);
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

int Fixed::getRawBits() const{
	std::cout << BCYA << "getRawBits member function called" << RES << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	std::cout << BCYA << "setRawBits member function called" << RES << std::endl;
	this->_fixedPointValue = raw;
}