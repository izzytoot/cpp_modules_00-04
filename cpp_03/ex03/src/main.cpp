/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:59 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/20 17:50:18 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main(){
	std::cout << std::endl;
	std::cout <<  BCYA << "*** Creating a DiamondTrap to test chaining***" << RES << std::endl;
	std::cout << std::endl;
	
	DiamondTrap mia("Mia");

	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing that attributes were initialized correctly ***" << RES << std::endl;
	std::cout << std::endl;
	
	std::cout << mia.printName() << " has the following points: "
			  << mia.getHit() << " hit points, "
			  << mia.getEnergy() << " energy points, "
			  << mia.getDamage() << " damage points."
			  << std::endl;

	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing that attack() comes from ScavTrap and the others come from ClapTrap ***" << RES << std::endl;
	std::cout << std::endl;

	mia.attack("Sornas");
	std::cout << BYEL << "DiamondTrap " << mia.printName() << " is repaired." << RES << std::endl;
	mia.beRepaired(50);
	std::cout << BYEL << "DiamondTrap " << mia.printName() << " takes damage." << RES << std::endl;
	mia.takeDamage(500);
	
	std::cout << std::endl;
	std::cout <<  BCYA << "*** Testing whoAmI ***" << RES << std::endl;
	std::cout << std::endl;

	mia.whoAmI();
	std::cout << std::endl;

	return 0;
}