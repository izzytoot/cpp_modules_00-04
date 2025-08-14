/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:02:28 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/13 10:45:24 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/
// constructor - creates a Fixed object
// initiates _fixedPointValue to 0
// it's called when creating a new object without arguments
Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << GRN << "Default constructor called" << RES << std::endl;
}

// copy constructor - creares a new oject as a copy of an existig one
// example Fixed b(a);, where a has been previously created
Fixed::Fixed(const Fixed& src){
	std::cout << GRN << "Copy constructor called" << RES << std::endl;
	*this = src; //uses copy assignment operator
}

// destructor - runs automatically when an object goes out of scope or is deleted
// cleans resources
Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
// copy assignment operator - assigns one existing object to another
// example: Fixed a, b; b = a;
// Fixed& means that the return value is a reference to a the current object. Without the reference we would be returning a copy
Fixed& Fixed::operator = (const Fixed& otherFixed){
	std::cout << YEL << "Copy assignment operator called" << RES << std::endl;
	if (this != &otherFixed) //checks for self assignment (a == a;)
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