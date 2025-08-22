/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:59 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 12:00:01 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main(){
	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing ClapTrap ***" << RES << std::endl;
	std::cout << std::endl;
	
	ClapTrap isa("Isabel");
	std::cout << isa.getName() << " has the following points: "
			  << isa.getHit() <<" hit points, "
			  << isa.getEnergy() <<" energy points and "
			  << isa.getDamage() <<" damage points." 
			  << std::endl;

	std::cout << std::endl << BCYA << "*** Testing member functions with valid values ***" << RES << std::endl;
	isa.attack("Filipe");
	isa.takeDamage(5);
	isa.beRepaired(1);

	std::cout << std::endl << BCYA << "*** Testing member functions with invalid or too high values ***" << RES << std::endl;
	isa.attack("");
	isa.takeDamage(-5);
	isa.beRepaired(-5);
	isa.takeDamage(8);
	isa.beRepaired(5);
	
	std::cout << std::endl;

	ClapTrap rodri("Rodrigo");
	std::cout << rodri.getName() << " has the following points: "
			  << rodri.getHit() <<" hit points, "
			  << rodri.getEnergy() <<" energy points and "
			  << rodri.getDamage() <<" damage points." 
			  << std::endl;
	
	std::cout << std::endl << BCYA << "*** Testing repair after spending all energy points on attacks ***" << RES << std::endl;
	
	for (int i = 0; i < 10; i++)
		rodri.attack("Philip");
	rodri.attack("one more?");
	rodri.beRepaired(5);

	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing FragTrap ***" << RES << std::endl;
	std::cout << std::endl;

	FragTrap biscoito("Biscoito");
	std::cout << biscoito.getName() << " has the following points: "
			  << biscoito.getHit() << " hit points, "
			  << biscoito.getEnergy() << " energy points, "
			  << biscoito.getDamage() << " damage points."
			  << std::endl;

	std::cout << std::endl << BCYA << "*** Testing highFives ability ***" << RES << std::endl;
	biscoito.highFivesGuys();
	
	std::cout << std::endl << BCYA << "*** Testing member functions with valid values ***" << RES << std::endl;
	biscoito.attack("Pipes");
	biscoito.takeDamage(99);
	biscoito.beRepaired(3);

	std::cout << std::endl << BCYA << "*** Testing member functions with invalid or too high values ***" << RES << std::endl;
	biscoito.attack("");
	biscoito.takeDamage(-5);
	biscoito.beRepaired(-5);
	biscoito.takeDamage(500); 
	biscoito.beRepaired(5);
	
	std::cout << std::endl;

	FragTrap pascal("Pascal");
	std::cout << pascal.getName() << " has the following points: "
			  << pascal.getHit() <<" hit points, "
			  << pascal.getEnergy() <<" energy points and "
			  << pascal.getDamage() <<" damage points." << RES << std::endl;
	
	std::cout << std::endl << BCYA << "*** Testing repair and attack after spending all energy points on attacks ***" << RES << std::endl;
	
	for (int i = 0; i < 100; i++)
		pascal.attack("Sornas");
	pascal.attack("one more?");
	pascal.beRepaired(10);

	std::cout << std::endl;
	return 0;
}