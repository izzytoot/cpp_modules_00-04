/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:59 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/15 22:34:31 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main(){
	std::cout << std::endl;
	ClapTrap isa("isabel");
	std::cout << isa.getName() << " has the following points: "
			  << isa.getHit() <<" hit points, "
			  << isa.getEnergy() <<" energy points and "
			  << isa.getDamage() <<" damage points." << RES << std::endl;

	std::cout << std::endl << BYEL << "*** Testing member functions with valid values ***" << RES << std::endl;
	isa.attack("Filipe");
	isa.takeDamage(5);
	isa.beRepaired(1);

	std::cout << std::endl << BYEL << "*** Testing member functions with invalid or too high values ***" << RES << std::endl;
	isa.attack("");
	isa.takeDamage(-5);
	isa.beRepaired(-5);
	isa.takeDamage(8); //with 6 hit points
	isa.beRepaired(5); //with 0 hit points
	
	std::cout << std::endl;

	ClapTrap rodri("rodrigo");
	std::cout << rodri.getName() << " has the following points: "
			  << rodri.getHit() <<" hit points, "
			  << rodri.getEnergy() <<" energy points and "
			  << rodri.getDamage() <<" damage points." << RES << std::endl;
	
	std::cout << std::endl << BYEL << "*** Testing repair after spending all energy points on attacks ***" << RES << std::endl;
	
	for (int i = 0; i < 10; i++)
		rodri.attack("Philip");
	rodri.beRepaired(5);

	std::cout << std::endl;
	std::cout << std::endl << BYEL << "*** Now all again with ScavTrap ***" << RES << std::endl;
	
	ScavTrap quiwi("Quiwi");
	std::cout << quiwi.getName() << " has the following points: "
			  << quiwi.getHit() <<" hit points, "
			  << quiwi.getEnergy() <<" energy points and "
			  << quiwi.getDamage() <<" damage points." << RES << std::endl;

	std::cout << std::endl << BYEL << "*** Testing member functions with valid values ***" << RES << std::endl;
	quiwi.attack("Sushi");
	quiwi.takeDamage(99);
	quiwi.beRepaired(3);

	std::cout << std::endl << BYEL << "*** Testing member functions with invalid or too high values ***" << RES << std::endl;
	quiwi.attack("");
	quiwi.takeDamage(-5);
	quiwi.beRepaired(-5);
	quiwi.takeDamage(500); 
	quiwi.beRepaired(5);
	
	std::cout << std::endl;

	ScavTrap santi("Santiago");
	std::cout << santi.getName() << " has the following points: "
			  << santi.getHit() <<" hit points, "
			  << santi.getEnergy() <<" energy points and "
			  << santi.getDamage() <<" damage points." << RES << std::endl;
	
	std::cout << std::endl << BYEL << "*** Testing repair after spending all energy points on attacks ***" << RES << std::endl;
	
	for (int i = 0; i < 50; i++)
		santi.attack("Jack");
	santi.beRepaired(20);
	
	std::cout << std::endl;
	return 0;
}