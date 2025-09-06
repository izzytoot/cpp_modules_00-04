/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:40:16 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/06 16:24:55 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Cure::Cure(): AMateria("cure"){
    std::cout << BGRN 
              << "Cure was constructed" 
              << RES << std::endl;
}

Cure::Cure(const Cure& src): AMateria("cure"){
    *this = src;
    std::cout << BGRN 
              << "Cure was copied and constructed" 
              << RES << std::endl;
}

Cure::~Cure(){
    std::cout << BRED 
              << "Cure was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Cure& Cure::operator= (const Cure& src){
   if (this != &src){
        this->_type = src._type;
   }
    std::cout << BGRN 
              << "Cure was copied with operator" 
              << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

AMateria* Cure::clone()const{ //understand better
    return new Cure(*this);
}

void Cure::use(ICharacter& target){
    std::cout << BCYA
              << "* heals "
              << target->getName()
              << "'s wounds *"
              << RES << std::endl;
}