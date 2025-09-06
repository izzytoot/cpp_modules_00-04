/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:59:24 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/26 13:30:19 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

AMateria::AMateria(): _type("no type"){
    std::cout << BGRN 
              << "AMateria was default constructed" 
              << RES << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type){
     std::cout << BGRN 
              << "AMateria was constructed with type" 
              << RES << std::endl;
}
  
AMateria::AMateria(const AMateria& src){
    *this = src;
    std::cout << BGRN 
              << "AMateria was copied and constructed" 
              << RES << std::endl;
}

AMateria::~AMateria(){
    std::cout << BRED 
              << "AMateria was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

AMateria& AMateria::operator= (const AMateria& src){
    if (this != &src)
        this->_type = src._type;
    std::cout << BGRN 
              << "AMateria was copied with operator" 
              << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/
std::string const & AMateria::getType() const{
    return this->_type;
}
 
virtual void AMateria::use(ICharacter& target){ //understand better
    void(target);
}