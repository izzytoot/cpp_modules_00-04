/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/06 18:26:03 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

Zombie::Zombie(){};

Zombie::~Zombie(){
	std::cout << RED << this->_name << " was destroyed." << RES << std::endl;
};

/*******************************************************************/
/*                      Getters / Setters                          */
/*******************************************************************/

void Zombie::setName(std::string name){
	this->_name = name;
}

std::string Zombie::getName() const{
	return this->_name;
}

/*******************************************************************/
/*                     Methods / Member function                   */
/*******************************************************************/

void Zombie::announce(){
	std::cout << YEL << this->_name << ": BraiiiiiiinnnzzzZ..." << RES << std::endl;
}