/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:53:20 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/21 17:35:01 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Cat::Cat(): Animal(){
	this->_type = "Cat";
	std::cout << BGRN
			  << "Cat was constructed."
			  << RES << std::endl;
}

Cat::Cat(Cat& src): Animal(src){
	*this = src;
	std::cout << BGRN
			  << "Cat was copied and constructed."
			  << RES << std::endl;
}

Cat::~Cat(){
	std::cout << BRED
			  << "Cat was destructed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
Cat& Cat::operator= (const Cat& src){
	if (this != &src){
		this->_type = src._type;
	}
	std::cout << BYEL
			  << "Cat src was copied into existing Cat obj."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void Cat::makeSound() const{
	std::cout << "miau miau" << std::endl;
}