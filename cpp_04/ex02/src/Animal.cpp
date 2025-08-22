/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:53:05 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 19:01:20 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
AAnimal::AAnimal(): _type("no Animal type"){
	std::cout << BGRN
			  << "Animal was constructed"
			  << RES << std::endl;
}

AAnimal::AAnimal(const AAnimal& src){
	*this = src;
	std::cout << BGRN
			  << "Animal was copied and constructed"
			  << RES << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << BRED
			  << "Animal was destroyed"
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

AAnimal& AAnimal::operator= (const AAnimal& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BYEL
			  << "Animal was copied and assigned into existing Animal"
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string AAnimal::getType() const{
	return this->_type;
}

