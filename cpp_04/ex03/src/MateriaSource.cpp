/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:01:10 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/06 21:39:16 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/IMateriaSource.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
MateriaSource::MateriaSource(){
     for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
    std::cout << BGRN 
              << "MateriaSource was default constructed" 
              << RES << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src){
    for (int i = 0; i < 4; i++){
         if (src._materias[i])
            this->_materias[i] = src._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    std::cout << BGRN 
              << "MateriaSource was copied and constructed" 
              << RES << std::endl;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        delete this->_materias[i];
        _materias[i] = NULL;
    }
    std::cout << BRED 
              << "MateriaSource was destructed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

MateriaSource& MateriaSource::operator = (const MateriaSource& src){
    if (this != src){
        for (int i = 0; i < 4; i++){
            delete this->_materias[i];
            if (src._materias[i])
                this->_materias[i] = src._materias[i]->clone();
            else
                this->_materias[i] = NULL;
        }
    }
    std::cout << BGRN 
              << "MateriaSource was copied with operator" 
              << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void MateriaSource::learnMateria(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (!this->_materias[i]){
            this->_materias[i] = m->clone();
            std::cout << GRN
                      << "Materia of type "
                      << m->getType()
                      << " learnt."
            return;
        }
    }
    std::cout << RED
              << "MateriaSource cannot learn more materias."
              << RES << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if (this->_materias[i] && this->_materias[i]->getType == type)
            return this->_materias[i]->clone;
    }
    std::cout << RED
              << "Cannot create new MateriaSource: type not found."
              << RES << std::endl;
    return NULL;
}