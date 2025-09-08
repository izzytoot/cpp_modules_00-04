/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:26:00 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/08 12:58:05 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Fire.hpp"
#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/IMateriaSource.hpp"

int main()
{
	std::cout << BCYA
			  << "*** BUILDING A MATERIA SOURCE THAT LEARNS ICE AND CURE***"
			  << RES << std::endl;
    IMateriaSource* materia_src = new MateriaSource(); //materiasource constructed and alocated to src
    materia_src->learnMateria(new Ice()); //materiasource learns ice through cloning it
    materia_src->learnMateria(new Cure()); //materiasource learns cure through cloning it
    materia_src->learnMateria(new Fire());
	
	std::cout << std::endl << BCYA
			  << "*** CREATING A CHARACTER ***"
			  << RES << std::endl; 
    ICharacter* isabel = new Character("Isabel");
	
	std::cout << std::endl << BCYA
			  << "*** EQUIPTING CHARACTER WITH MATERIAS EXTRACTED FROM MATERIA SOURCE ***"
			  << RES << std::endl;
    AMateria* tmp;
    tmp = materia_src->createMateria("ice");
    isabel->equip(tmp);
    tmp = materia_src->createMateria("cure");
    isabel->equip(tmp);
	tmp = materia_src->createMateria("fire");
	isabel->equip(tmp);

	std::cout << std::endl << BCYA
			  << "*** CRETING ANOTHER CHARACTER ***"
			  << RES << std::endl;
    ICharacter* filipe = new Character("Filipe");

	std::cout << std::endl << BCYA
			  << "*** ISABEL USING MATERIALS (ICE AND CURE) ON FILIPE ***"
			  << RES << std::endl;
    isabel->use(0, *filipe);
    isabel->use(1, *filipe);
	isabel->use(2, *filipe);
    
	std::cout << std::endl << BCYA
			  << "*** DELETING AND CLEANING ***"
			  << RES << std::endl;
    delete filipe;
    delete isabel;
    delete materia_src;
    
    return 0;
}