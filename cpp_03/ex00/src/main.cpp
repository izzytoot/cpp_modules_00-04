/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:59 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 11:32:50 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main(){
	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing ClapTrap ***" << RES << std::endl;
	std::cout << std::endl;
	ClapTrap isa("Isabel");
	std::cout << isa.getName() << " has the following points: "
			  << isa.getHit() <<" hit points, "
			  << isa.getEnergy() <<" energy points and "
			  << isa.getDamage() <<" damage points." << RES << std::endl;

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
			  << rodri.getDamage() <<" damage points." << RES << std::endl;
	
	std::cout << std::endl << BCYA << "*** Testing repair and attack after spending all energy points on attacks ***" << RES << std::endl;
	
	for (int i = 0; i < 10; i++)
		rodri.attack("Philip");
	rodri.attack("one more?");
	rodri.beRepaired(5);
	
	std::cout << std::endl;
	return 0;
}