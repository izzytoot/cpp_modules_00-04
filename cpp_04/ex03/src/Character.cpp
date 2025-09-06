/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:48:14 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/06 21:38:59 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Character::Character(): _name("nameless") { //why not call AMateria()??
    for (int i = 0; i < 4; i++)
        inv_materia[i] = NULL; //NULL or 0?
    std::cout << BGRN 
              << "Character was default constructed" 
              << RES << std::endl;
}

Character::Character(std::str name): _name(name) {
    for (int i = 0; i < 4; i++)
        inv_materia[i] = NULL;
    std::cout << BGRN 
              << "Character with name was constructed" 
              << RES << std::endl;
}

Character::Character(const Character& src): _name(src->_name){
    for (int i = 0; i < 4; i++){
         if (src.inv_materia[i])
            this->inv_materia[i] = src.inv_materia[i]->clone(); //clone creates new materia (ice or cure)
        else
            this->inv_materia[i] = NULL;
    }
    std::cout << BGRN 
              << "Character was copied and constructed" 
              << RES << std::endl;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        delete this->inv_materia[i];
        inv_materia[i] = NULL;
    }
    std::cout << BRED 
              << "Character was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Character& Character::operator = (const Character& src){
    if (this != src){
        this->_name = src._name;
        for (int i = 0; i < 4; i++){
            delete this->inv_materia[i];
            if (src.inv_materia[i])
                this->inv_materia[i] = src.inv_materia[i]->clone();
            else
                this->inv_materia[i] = NULL;
        }
    }
    std::cout << BGRN 
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
        if (!this->inv_materia[i]){
            this->inv_materia[i] = m;
            std::cout << GRN
                      << "Materia added to Character "
                      << this->getName()
                      << "'s inventory."
                      << RES << std::endl;
            return ;
        }
    std::cout << RED
                  << "Full inventory: unable to equip Character "
                   << this->getName()
                  << "'s inventory."
                  << RES << std::endl;
    delete m;
    }
}

void Character::unequip(int idx){
    if ((idx < 0 || idx > 3 )|| !this->inv_materia[idx]){
         std::cout << RED
                  << "Unknown materia slot: unable to unequip."
                  << RES << std::endl;
    }
    this->inv_materia[idx] = NULL;
    std::cout << GRN
              << "Materia slot unequiped"
              << RES << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if ((idx < 0 || idx > 3) || !this->inv_materia[idx]){
         std::cout << RED
                  << "Unknown materia slot: unable to use."
                  << RES << std::endl;
    }
    this->inv_materia[idx]->use(target);
}