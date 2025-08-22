/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:53:20 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 18:50:48 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Cat::Cat(): Animal(){
	std::cout << BGRN
			  << "Cat was constructed."
			  << RES << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& src): Animal(src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain); //deep copy of brain. *this = src would be a shalow copy and they would literally share the same memory space
	std::cout << BGRN
			  << "Cat was copied and constructed."
			  << RES << std::endl;
}

Cat::~Cat(){
	delete _brain;
	std::cout << BRED
			  << "Cat was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
Cat& Cat::operator= (const Cat& src){
	if (this != &src){
		this->_type = src._type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain); //deep copy of brain
	}
	std::cout << BYEL
			  << "Cat was copied into existing Cat."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void Cat::makeSound() const{
	std::cout << "miau miau" << std::endl;
}

Brain* Cat::getBrain() const{
	return this->_brain;
}