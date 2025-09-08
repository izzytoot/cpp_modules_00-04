/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:52:47 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/23 11:27:46 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Dog::Dog(): AAnimal(){
	std::cout << BGRN
			  << "Dog was constructed."
			  << RES << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& src): AAnimal(src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	std::cout << BGRN
			  << "Dog was copied and constructed."
			  << RES << std::endl;
}

Dog::~Dog(){
	delete _brain;
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
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << BYEL
			  << "Dog was copied into existing Dog."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void Dog::makeSound() const{
	std::cout << "wof wof" << std::endl;
}

Brain* Dog::getBrain() const{
	return this->_brain;
}