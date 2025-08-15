/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/15 13:13:11 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/

ClapTrap::ClapTrap(): _name("to be named"), _hit(10), _energy(10), _damage(0) {
	std::cout << BGRN << "Nameless ClapTrap was created" << RES << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << BGRN << _name << " was created" << RES << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << BYEL << src._name << " was copyed into new ClapTrap" << RES << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	if (_name != "to be named")
		std::cout << BRED << _name << " was destroyed" << RES << std::endl << std::endl;
	else
		std::cout << BRED << "nameless ClapTrap was destroyed" << RES << std::endl << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

ClapTrap& ClapTrap::operator= (const ClapTrap& src){
	std::cout << BYEL << src._name << "was copyed into existing ClapTrap" << RES << std::endl;
	if (this != &src){
		this->_name = src._name;
		this->_hit = src._hit;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return *this;
}

/******************************************************************************/
/*                              Getter Functions                              */
/******************************************************************************/

std::string ClapTrap::getName(){
	return this->_name;
}
int ClapTrap::getHit(){
	return this->_hit;
}
int ClapTrap::getEnergy(){
	return this->_energy;
}
int ClapTrap::getDamage(){
	return this->_damage;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void ClapTrap::attack(const std::string& target){
	std::cout << BCYA << this->_name << " is trying to attack " << target << RES << std::endl;
	
	if (this->_hit <= 0){
		std::cout << RED << this->_name << "needs more hit points to attack." << RES << std::endl;
		return ;
	}
	if (this->_energy <= 0){
		std::cout << RED << this->_name << "needs more energy points to attack." << RES << std::endl;
		return ;
	}
	
	std::cout << YEL << this->_name << " attacked " << target << " with xx points of damage." << RES << std::endl;
	this->_energy--;
	std::cout << YEL << this->_name << " has " << this->_energy << " energy points remaining." << RES << std::endl;

	return ;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << BCYA << this->_name << " is trying to take damage of " << amount << " hit points." RES << std::endl;

	int sub = this->_hit - amount;
	
	if (sub < 0){
		std::cout << RED << this->_name << "needs can't take the damage." << RES << std::endl;
		std::cout << YEL << this->_name << " has now 0 hit points." << RES << std::endl;
		this->_hit = 0;
		return ;
	}
	
	this->_hit = sub;
	
	std::cout << YEL << this->_name << " was attacked with " << amount << " points of damage." << RES << std::endl;
	std::cout << YEL << this->_name << " has " << this->_hit << " hit points." << RES << std::endl;

	return ;
}


void ClapTrap::beRepaired(unsigned int amount){
	std::cout << BCYA << this->_name << " is trying to recover " << amount << "hit points." << RES << std::endl;
	
	if (this->_hit <= 0){
		std::cout << RED << this->_name << "needs more hit points to be repaired." << RES << std::endl;
		return ;
	}
	if (this->_energy <= 0){
		std::cout << RED << this->_name << "needs more energy points to be repaired." << RES << std::endl;
		return ;
	}
	
	this->_hit += amount;
	std::cout << YEL << this->_name << " was repaired with " << amount << " points of damage." << RES << std::endl;
	std::cout << YEL << this->_name << " has " << this->_hit << " hit points." << RES << std::endl;

	this->_energy--;
	std::cout << YEL << this->_name << " has " << this->_energy << " energy points remaining." << RES << std::endl;
	return ;
}

//energy points should be taken at the beginning or the end of attack and repair?
//can repair be made on an obj with 0 hit points?
//can't default constructor have no attributes?