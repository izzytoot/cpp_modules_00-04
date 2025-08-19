/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/19 19:47:16 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/
DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap() {
	setName("to be named");
	setHit(FragTrap::getHit());
	setEnergy(ScavTrap::getEnergy());
	setDamage(FragTrap::getDamage());
	std::cout << BGRN 
			  << "Nameless DiamondTrap was constructed." 
			  << RES << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "clapName"), FragTrap(), ScavTrap(){
	this->_name = name;
	setHit(FragTrap::getHit()); //100
	setEnergy(ScavTrap::getEnergy()); //50
	setDamage(FragTrap::getDamage()); //30
	std::cout << BGRN 
			  << "DiamondTrap " 
			  << name 
			  << " was constructed." 
			  << RES << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), FragTrap(src), ScavTrap(src) {
	std::cout << BGRN
			  << "DiamondTrap "
			  << src.getName() 
			  << " was constructed and copied." 
			  << RES << std::endl;
}
				
DiamondTrap::~DiamondTrap(){
	if (getName() != "to be named"){
		std::cout << BRED 
				  << "DiamondTrap " 
				  << getName() 
				  << " was destroyed." 
				  << RES << std::endl;

	}
	else{
		std::cout << BRED 
				 << "Nameless DiamondTrap was destroyed." 
				 << RES << std::endl;
	}
}
/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& src){
	std::cout << BYEL 
			  << "DiamondTrap "
			  << src.getName() 
			  << " was and copied into existing DiamondTrap named "
			  << _name
			  << "." 
			  << RES << std::endl;
	if (this != &src)
		DiamondTrap::operator=(src);
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void DiamondTrap::whoAmI(){
	std::cout << "I am DiamondTrap"
			  << _name
			  <<" and my ClapTrap is "
			  << ClapTrap::getName()
			  << std::endl;
}