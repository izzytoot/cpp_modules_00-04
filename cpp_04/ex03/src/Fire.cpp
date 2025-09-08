/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:39:51 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/08 12:58:18 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fire.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Fire::Fire(): AMateria("fire"){
    std::cout << BGRN 
              << "Ice was constructed" 
              << RES << std::endl;
}

Fire::Fire(const Fire& src): AMateria("fire"){
    *this = src;
    std::cout << BGRN 
              << "Fire was copied and constructed" 
              << RES << std::endl;
}

Fire::~Fire(){
    std::cout << BRED 
              << "Fire was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Fire& Fire::operator= (const Fire& src){
    if (this != &src)
		AMateria::operator= (src);
    std::cout << BYEL 
              << "Fire was copied with operator" 
              << RES << std::endl;
    return *this;
    
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

AMateria* Fire::clone()const{ //understand better
    return new Fire(*this);
}

void Fire::use(ICharacter& target){
    std::cout << CYA
              << "FIRE: * shoots a fire at strike "
              << target.getName()
              << " *"
              << RES << std::endl;
}
