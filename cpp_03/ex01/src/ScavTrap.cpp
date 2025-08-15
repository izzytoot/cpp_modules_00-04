/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/15 22:25:08 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/
ScavTrap::ScavTrap(): ClapTrap() {
	setName("to be named");
	setHit(100);
	setEnergy(50);
	setDamage(20);
	std::cout << BGRN 
			  << "Nameless ScavTrap was constructed." 
			  << RES << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	setHit(100);
	setEnergy(50);
	setDamage(20);
	std::cout << BGRN 
			  << "ScavTrap " 
			  << name 
			  << " was constructed." 
			  << RES << std::endl;
}

//here we don't copy this = src because it would be reduntant. It has already been done in the base class copy constructor ClapTrap(src).
ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) {
	std::cout << BYEL
			  << "ScavTrap "
			  << src.getName() 
			  << " was constructed and copied." 
			  << RES << std::endl;
}
				
ScavTrap::~ScavTrap(){
	if (getName() != "to be named"){
		std::cout << BRED 
				  << "ScavTrap " 
				  << getName() 
				  << " was destroyed." 
				  << RES << std::endl;

	}
	else{
		std::cout << BRED 
				 << "Nameless ScavTrap was destroyed." 
				 << RES << std::endl;
	}
}
/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

ScavTrap& ScavTrap::operator= (const ScavTrap& src){
	std::cout << BYEL 
			  << "ScavTrap "
			  << src.getName() 
			  << " was and copied into existing ScavTrap." 
			  << RES << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	// if (this != &src){
	// 	this->setName(src.getName());
	// 	this->setHit(src.getHit());
	// 	this->setEnergy(src.getEnergy());
	// 	this->setDamage(src.getDamage());
	//}
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void ScavTrap::attack(std::string target){
	if (target.empty()){
		std::cout << RED 
				  << "ERROR: target needed to perform ScavTrap attack." 
				  << RES << std::endl;
		return ;
	}
	
	std::cout << BCYA 
			  << "ScavTrap "
			  << this->getName() 
			  << " is trying to attack " 
			  << target 
			  << RES << std::endl;
	
	if (this->getHit() <= 0){
		std::cout << RED 
				  << "ERROR: ScavTrap "
				  << this->getName() 
				  << " needs more hit points to attack." 
				  << RES << std::endl;
		return ;
	}
	if (this->getEnergy() <= 0){
		std::cout << RED 
				  << "ERROR: ScavTrap " 
				  << this->getName() 
				  << " needs more energy points to attack." 
				  << RES << std::endl;
		return ;
	}

	this->setEnergy(getEnergy() - 1);
	
	std::cout << YEL
			  << "ScavTrap "
			  << this->getName() 
			  << " attacked " 
			  << target 
			  << " with " 
			  << this->getDamage() 
			  << " points of damage." 
			  << RES << std::endl;
	std::cout << YEL
			  << "ScavTrap "
			  << this->getName() 
			  << " spent 1 energy point on this attack and now has " 
			  << this->getEnergy() 
			  << " energy points remaining." 
			  << RES << std::endl;

	return ;
}
	
void ScavTrap::guardGate(){
	std::cout << YEL
			  << "ScavTrap "
			  << this->getName()
			  << "is now in Gate keeper mode." 
			  << RES << std::endl;			
}