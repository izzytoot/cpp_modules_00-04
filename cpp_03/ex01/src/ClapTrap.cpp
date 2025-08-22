/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 11:43:24 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/

ClapTrap::ClapTrap(): _name("to be named"), _hit(10), _energy(10), _damage(0) {
	std::cout << BGRN 
			  << "Nameless ClapTrap was constructed." 
			  << RES << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << BGRN 
			  << "ClapTrap "
			  << _name 
			  << " was constructed." 
			  << RES << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << BGRN
			  << "ClapTrap " 
			  << src._name 
			  << " was constructed and copied." 
			  << RES << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	if (_name != "to be named")
		std::cout << BRED 
				  << "ClapTrap "
				  << _name 
				  << " was destroyed." 
				  << RES << std::endl;
	else
		std::cout << BRED 
				  << "nameless ClapTrap was destroyed." 
				  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

ClapTrap& ClapTrap::operator= (const ClapTrap& src){
	std::cout << BYEL 
			  << "ClapTrap "
			  << src._name 
			  << " was copied into existing ClapTrap" 
			  << RES << std::endl;
	if (this != &src){
		this->_name = src._name;
		this->_hit = src._hit;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return *this;
}

/******************************************************************************/
/*                         Getter and Setter Functions                        */
/******************************************************************************/

std::string ClapTrap::getName() const{
	return this->_name;
}
int ClapTrap::getHit() const{
	return this->_hit;
}
int ClapTrap::getEnergy() const{
	return this->_energy;
}
int ClapTrap::getDamage() const{
	return this->_damage;
}

void ClapTrap::setName(std::string str){
	this->_name = str;
}

void ClapTrap::setHit(int val){
	this->_hit = val;
}

void ClapTrap::setEnergy(int val){
	this->_energy = val;
}

void ClapTrap::setDamage(int val){
	this->_damage = val;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void ClapTrap::attack(const std::string& target){
	//check if empty target
	if (target.empty()){
		std::cout << RED 
				  << "ERROR: target needed to perform ClapTrap attack." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << "ClapTrap "
			  << this->_name 
			  << " is trying to attack " 
			  << target 
			  << RES << std::endl;
	
	//check if enough hit and energy points to perform
	if (this->_hit <= 0){
		std::cout << RED 
				  << "ERROR: ClapTrap " 
				  << this->_name 
				  << " needs more hit points to attack." 
				  << RES << std::endl;
		return ;
	}
	if (this->_energy <= 0){
		std::cout << RED 
				  << "ERROR: ClapTrap " 
				  << this->_name 
				  << " needs more energy points to attack." 
				  << RES << std::endl;
		return ;
	}

	//remove energy point
	this->_energy--;
	
	//report what happened
	std::cout << "ClapTrap "
			  << this->_name 
			  << " attacked " 
			  << target << " with " 
			  << this->_damage 
			  << " points of damage." 
			  << RES << std::endl;
	std::cout << "ClapTrap "
			  << this->_name 
			  << " spent 1 energy point on this attack and now has " 
			  << this->_energy << " energy points remaining." 
			  << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount){
	//check if valid amount
	if ((int)amount < 0){
		std::cout << RED 
				  << "ERROR: invalid amount value." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << this->_name 
			  << " is trying to take a damage of "
			  << amount
			  << " hit points." 
			  << RES << std::endl;

	if (this->_hit == 0){
		std::cout << RED 
				  << "ERROR:" 
				  << this->_name 
				  << " is already dead." 
				  << RES << std::endl;
		return ;
	}

	//remove amount to hit
	int sub = this->_hit - amount;	
	
	//check if result is above 0
	if (sub < 0){
		std::cout << RED 
				  << this->_name 
				  << " can't take the damage. Needs more hit points." 
				  << RES << std::endl;
		std::cout << RED 
				  << this->_name 
				  << " has now 0 hit points." 
				  << RES << std::endl;
		this->_hit = 0;
		return ;
	}
	else{
		//substitute sub to hit
		this->_hit = sub;
	
		//report what happened
		std::cout << this->_name 
				  << " was attacked with " 
				  << amount 
				  << " points of damage." 
				  << std::endl;
		std::cout << this->_name 
				  << " has " << this->_hit 
				  << " hit points." 
				  << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	//check if valid amount
	if ((int)amount < 0){
		std::cout << RED 
				  << "ERROR: invalid amount value." 
				  << RES << std::endl;
		return ;
	}
	
	//init message
	std::cout << YEL 
			  << this->_name 
			  << " is trying to recover " 
			  << amount 
			  << " hit points." 
			  << RES << std::endl;
	
	//check if hit and energy points are enough to perform
	if (this->_hit <= 0){
		std::cout << RED 
				  << "ERROR: " 
				  << this->_name 
				  << " needs more hit points to be repaired." 
				  << RES << std::endl;
		return ;
	}
	if (this->_energy <= 0){
		std::cout << RED 
				  << "ERROR: " 
				  << this->_name 
				  << " needs more energy points to be repaired." 
				  << RES << std::endl;
		return ;
	}
	
	//remove energy point and add amount to hit
	this->_energy--;
	this->_hit += amount;
	
	//report what happened
	std::cout << this->_name 
			  << " was repaired with " 
			  << amount 
			  << " hit points." 
			  << std::endl;
	std::cout << this->_name 
			  << " has " 
			  << this->_hit 
			  << " hit points." 
			  << std::endl;
	std::cout << this->_name 
			  << " spent 1 energy point on this repair and now has " 
			  << this->_energy 
			  << " energy points remaining." 
			  << std::endl;
	return ;
}