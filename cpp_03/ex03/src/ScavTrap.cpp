/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 12:32:12 by icunha-t         ###   ########.fr       */
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
			  << "Default ScavTrap was constructed." 
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

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) {
	std::cout << BGRN
			  << "ScavTrap "
			  << src.getName() 
			  << " was constructed and copied." 
			  << RES << std::endl;
}
				
ScavTrap::~ScavTrap(){
		std::cout << BRED 
				 << "ScavTrap was destroyed." 
				 << RES << std::endl;
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
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void ScavTrap::attack(std::string target){
	//check if target is empty
	if (target.empty()){
		std::cout << RED 
				  << "ERROR: target needed to perform ScavTrap attack." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << "ScavTrap "
			  << this->getName() 
			  << " is trying to attack " 
			  << target 
			  << RES << std::endl;
	
	//check if hit and energy points are enough to perform
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

	//remove energy point
	this->setEnergy(getEnergy() - 1);
	
	//report what happened
	std::cout << "ScavTrap "
			  << this->getName() 
			  << " attacked " 
			  << target 
			  << " with " 
			  << this->getDamage() 
			  << " points of damage." 
			  << std::endl;
	std::cout << "ScavTrap "
			  << this->getName() 
			  << " spent 1 energy point on this attack and now has " 
			  << this->getEnergy() 
			  << " energy points remaining." 
			  << std::endl;

	return ;
}
	
void ScavTrap::guardGate(){
	std::cout << "ScavTrap "
			  << this->getName()
			  << " is now in GUard Gate mode." 
			  << std::endl;			
}