/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:00:48 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/23 11:21:53 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

WrongCat::WrongCat(): WrongAnimal(){
	_type = "WrongCat";
	std::cout << BGRN
			  << "WrongCat was constructed"
			  << RES << std::endl;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src){
	*this = src;
	std::cout << BGRN
			  << "WrongCat was copied and constructed"
			  << RES << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << BRED
			  << "WrongCat was destroyed"
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

WrongCat& WrongCat::operator= (const WrongCat& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BGRN
			  << "WrongCat copied into an existing WrongCat"
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void WrongCat::makeSound() const{
	std::cout << "wrong miau miau" << std::endl;
}
