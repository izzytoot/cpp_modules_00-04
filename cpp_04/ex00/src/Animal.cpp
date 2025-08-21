/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:53:05 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/21 18:28:15 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Animal::Animal(): _type("no Animal type"){
	std::cout << BGRN
			  << "Animal was constructed"
			  << RES << std::endl;
}

Animal::Animal(Animal& src){
	*this = src;
	std::cout << BGRN
			  << "Animal was copied from src and constructed"
			  << RES << std::endl;
}

Animal::~Animal(){
	std::cout << BRED
			  << "Animal was destructed"
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Animal& Animal::operator= (const Animal& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BYEL
			  << "Animal src was copied and assigned into existing Animal obj"
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string Animal::getType() const{
	return this->_type;
}

void Animal::makeSound() const{
	std::cout << "shhhhhhhh"
			  << std::endl;
}
