/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 12:30:22 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

Weapon::Weapon(std::string type) : _type(type) {} //sets initial type

Weapon::~Weapon(){};

/*******************************************************************/
/*                      Getters / Setters                          */
/*******************************************************************/

//check the current weapon type
const std::string& Weapon::getType() const {
	return this->_type;
}

//allows weapon type to be changed 
void Weapon::setType(const std::string& newType){
	this->_type = newType;
}
