/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:36:49 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/06 21:40:28 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

ICharacter::ICharacter(): _name("nameless") {
    std::cout << BGRN 
              << "ICharacter was default constructed" 
              << RES << std::endl;
}

ICharacter::ICharacter(std::str name): _name(name) {
    std::cout << BGRN 
              << "ICharacter was constructed" 
              << RES << std::endl;
}

ICharacter::ICharacter(const ICharacter& src){
    *this = src;
    std::cout << BGRN 
              << "ICharacter was copied and constructed" 
              << RES << std::endl;
}

ICharacter::~ICharacter(){
    std::cout << BRED 
              << "ICharacter was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

ICharacter& ICharacter::operator = (const ICharacter& src){
    if (this != src){
        this->_name = src._name;
    }
    std::cout << BGRN 
              << "ICharacter was copied with operator" 
              << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string ICharacter::getName(){
    return this->_name;
}
  