/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 12:30:31 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(){}

/*******************************************************************/
/*                      Getters / Setters                          */
/*******************************************************************/

void HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

/*******************************************************************/
/*                     Methods / Member function                   */
/*******************************************************************/

void HumanB::attack(){
	if (_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with." << std::endl;
}
