/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:40:16 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/08 12:39:30 by icunha-t         ###   ########.fr       */
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
	if (this != &src)
		AMateria::operator= (src);
	std::cout << BYEL
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
    std::cout << CYA
              << "CURE: * heals "
              << target.getName()
              << "'s wounds *"
              << RES << std::endl;
}