/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 16:32:19 by icunha-t         ###   ########.fr       */
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

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), FragTrap(), ScavTrap() {
	*this = src;
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

void DiamondTrap::takeDamage(unsigned int amount){
	//check if valid amount
	if ((int)amount < 0){
		std::cout << RED 
				  << "ERROR: invalid amount value." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << "DiamondTrap "
			  << this->_name 
			  << " is trying to take a damage of "
			  << amount
			  << " hit points." 
			  << RES << std::endl;

	if (this->getHit() == 0){
		std::cout << RED 
				  << "ERROR:" 
				  << this->_name 
				  << " is already dead." 
				  << RES << std::endl;
		return ;
	}

	//remove amount to hit
	int sub = this->getHit() - amount;	
	
	//check if result is above 0
	if (sub < 0){
		std::cout << RED 
				  << "DiamondTrap "
			 	  << this->_name  
				  << " can't take the damage. Needs more hit points." 
				  << RES << std::endl;
		std::cout << RED 
				  << this->_name 
				  << " has now 0 hit points." 
				  << RES << std::endl;
		this->setHit(0);
		return ;
	}
	else{
		//substitute sub to hit
		this->setHit(sub);

		//report what happened
		std::cout << "DiamondTrap "
				  << this->_name 
				  << " was attacked with " 
				  << amount 
				  << " points of damage." 
				  << std::endl;
		std::cout << this->_name 
				  << " has " << this->getHit() 
				  << " hit points." 
				  << std::endl;
		return ;
	}
}

void DiamondTrap::beRepaired(unsigned int amount){
	//check if valid amount
	if ((int)amount < 0){
		std::cout << RED 
				  << "ERROR: invalid amount value." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << "DiamondTrap "
			  << this->_name 
			  << " is trying to recover " 
			  << amount 
			  << " hit points." 
			  << RES << std::endl;
	
	//check if hit and energy points are enough to perform
	if (this->getHit() <= 0){
		std::cout << RED 
				  << "ERROR: " 
				  << this->_name 
				  << " needs more hit points to be repaired." 
				  << RES << std::endl;
		return ;
	}
	if (this->getEnergy() <= 0){
		std::cout << RED 
				  << "ERROR: " 
				  << this->_name 
				  << " needs more energy points to be repaired." 
				  << RES << std::endl;
		return ;
	}
	
	//remove energy point and add amount to hit
	this->setEnergy(this->getEnergy() - 1);
	this->setHit(this->getHit() + amount);

	//report what happened
	std::cout << "DiamondTrap "
			  << this->_name 
			  << " was repaired with " 
			  << amount 
			  << " hit points." 
			  << std::endl;
	std::cout << "DiamondTrap "
			  << this->_name  
			  << " has " 
			  << this->getHit() 
			  << " hit points." 
			  << std::endl;
	std::cout << "DiamondTrap "
			  << this->_name 
			  << " spent 1 energy point on this repair and now has " 
			  << this->getEnergy() 
			  << " energy points remaining." 
			  << std::endl;
	return ;
}