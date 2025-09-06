/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:39:51 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/06 16:24:48 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Ice::Ice(): AMateria("ice"){
    std::cout << BGRN 
              << "Ice was constructed" 
              << RES << std::endl;
}

Ice::Ice(const Ice& src): AMateria("ice"){
    *this = src;
    std::cout << BGRN 
              << "Ice was copied and constructed" 
              << RES << std::endl;
}

Ice::~Ice(){
    std::cout << BRED 
              << "Ice was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Ice& operator= (const Ice& src){
    if (this != src){
        this->_type = src._type;
    }
    std::cout << BGRN 
              << "Ice was copied with operator" 
              << RES << std::endl;
    return *this;
    
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

AMateria* Ice::clone()const{ //understand better
    return new Ice(*this);
}

void Ice::use(ICharacter& target){
    std::cout << BCYA
              << "* shoots an ice bolt at "
              << target->getName()
              << " *"
              << RES << std::endl;
}
