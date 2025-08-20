/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/20 17:51:54 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/
DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap() {
	setName("to be named");
	setHit(100);
	setEnergy(50);
	setDamage(30);
	std::cout << BGRN 
			  << "Default DiamondTrap was constructed." 
			  << RES << std::endl;
}

//constructor declaration defines how the bases should be initializes when a DiamonTrap obj is created
//constructor itself is not declaring inheritance anymore
//"When I construct a DiamondTrap, here’s how I want to initialize my bases and my own members.""
//ClapTrap(name + "clapName") initializes the shared virtual ClapTrap subobj
//FragTrap and ScavTrap construct the inhereted parts of DiamondTrap
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
	_name = name;
	setHit(100); //FragTrap
	setEnergy(50); //ScavTrap
	setDamage(30); //FragTrap
	std::cout << BGRN 
			  << "DiamondTrap " 
			  << name 
			  << " was constructed." 
			  << RES << std::endl;
}

//we call the copy constructors of the bases so each base copies the corresponding state from src
//we are reusing src's initialization
DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), FragTrap(), ScavTrap() {
	*this = src; //we need to make sure the unique member _name is also copied
	std::cout << BGRN
			  << "DiamondTrap "
			  << src._name
			  << " was constructed and copied." 
			  << RES << std::endl;
}
				
DiamondTrap::~DiamondTrap(){
		std::cout << BRED 
				 << "DiamondTrap was destroyed." 
				 << RES << std::endl;
}
/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& src){
	//copy each part of ClapTrap, FragTap, ScavTrap and DiamondTrap 
	if (this != &src){
		this->_name = src._name;
		this->setHit(src.getHit());
		this->setEnergy(src.getEnergy());
		this->setDamage(src.getDamage());		
	}
	std::cout << BYEL 
			  << "DiamondTrap "
			  << src._name 
			  << " was and copied into existing DiamondTrap named "
			  << this->_name
			  << "." 
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void DiamondTrap::attack(std::string target){
	std::cout << BYEL 
			  << "DiamondTrap " 
			  << this->_name 
			  << " (via ScavTrap) attacks!" 
			  << RES << std::endl;
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am DiamondTrap "
			  << this->_name
			  <<" and my ClapTrap is "
			  << ClapTrap::getName()
			  << std::endl;
}

std::string DiamondTrap::printName(){
	return this->_name;
}