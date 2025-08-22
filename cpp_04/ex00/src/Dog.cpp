/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:52:47 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 18:30:37 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Dog::Dog(): Animal(){
	this->_type = "Dog";
	std::cout << BGRN
			  << "Dog was constructed."
			  << RES << std::endl;
}

Dog::Dog(const Dog& src): Animal(src){
	*this = src;
	std::cout << BGRN
			  << "Dog was copied and constructed."
			  << RES << std::endl;
}

Dog::~Dog(){
	std::cout << BRED
			  << "Dog was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
Dog& Dog::operator= (const Dog& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BYEL
			  << "Dog src was copied into existing Dog obj."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void Dog::makeSound() const{
	std::cout << "wof wof" << std::endl;
}