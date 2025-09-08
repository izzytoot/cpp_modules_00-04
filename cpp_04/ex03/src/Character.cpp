/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:48:14 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/08 12:59:22 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Character::Character(): _name("nameless") { //why not call AMateria()??
    for (int i = 0; i < 4; i++)
        _mat_slots[i] = NULL; //NULL or 0?
    std::cout << BGRN 
              << "Character was default constructed" 
              << RES << std::endl;
}

Character::Character(std::string name): _name(name) {
    for (int i = 0; i < 4; i++)
        _mat_slots[i] = NULL;
    std::cout << BGRN 
              << "Character with name \""
			  << name
			  << "\" was constructed"
              << RES << std::endl;
}

Character::Character(const Character& src): _name(src._name){
    for (int i = 0; i < 4; i++){
         if (src._mat_slots[i])
            this->_mat_slots[i] = src._mat_slots[i]->clone(); //clone creates new materia (ice or cure)
        else
            this->_mat_slots[i] = NULL;
    }
    std::cout << BGRN 
              << "Character was copied and constructed" 
              << RES << std::endl;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        delete this->_mat_slots[i];
        this->_mat_slots[i] = NULL;
    }
    std::cout << BRED 
              << "Character was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Character& Character::operator = (const Character& src){
    if (this != &src){
        this->_name = src._name;
        for (int i = 0; i < 4; i++){
            delete this->_mat_slots[i];
			this->_mat_slots[i] = NULL;
        }
		for (int i = 0; i < 4; i++)
			this->_mat_slots[i] = src._mat_slots[i]->clone();
    }
    std::cout << BYEL 
              << "Character was copied with operator" 
              << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/


std::string const & Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria* m){
    if (!m)
    {
        std::cout << RED
                  << "Unknown materia: unable to equip Character "
                  << this->getName()
                  << "'s inventory."
                  << RES << std::endl;
    }
    for (int i = 0; i < 4; i++){
        if (!this->_mat_slots[i]){
            this->_mat_slots[i] = m;
            std::cout << CYA
                      << "Materia of type "
					  << m->getType()
					  << " added to Character "
                      << this->getName()
                      << "'s inventory."
                      << RES << std::endl;
            return ;
        }
	}
    std::cout << RED
                  << "Full inventory: unable to equip Character "
                   << this->getName()
                  << "'s inventory."
                  << RES << std::endl;
}

void Character::unequip(int idx){
    if ((idx < 0 || idx > 3 )|| !this->_mat_slots[idx]){
         std::cout << RED
                  << "Unknown materia slot: unable to unequip."
                  << RES << std::endl;
    }
    this->_mat_slots[idx] = NULL;
    std::cout << CYA
              << "Materia slot unequiped"
              << RES << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if ((idx < 0 || idx > 3) || !this->_mat_slots[idx]){
         std::cout << RED
                  << "Unknown materia slot: unable to use."
                  << RES << std::endl;
    }
    this->_mat_slots[idx]->use(target);
}
