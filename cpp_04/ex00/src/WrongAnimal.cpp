/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:19:33 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/21 18:37:36 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

WrongAnimal::WrongAnimal(): _type("no WrongAnimal type"){
	std::cout << BGRN
			  << "WrongAnimal was constructed"
			  << RES << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& src){
	*this = src;
	std::cout << BGRN
			  << "WrongAnimal was copied from src and constructed"
			  << RES << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << BRED
			  << "WrongAnimal was destructed"
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BGRN
			  << "WrongAnimal copied from src into an existing Wronganimal"
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void WrongAnimal::makeSound() const{
	std::cout << "wrong shhhhhhhhhh" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}