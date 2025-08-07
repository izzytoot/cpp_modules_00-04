/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 13:03:56 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"
#include "../inc/Weapon.hpp"

int main(){
	std::cout << BYEL << " *** Creating Human A *** " << RES << std::endl;
	Weapon sword("sword");
	std::cout << BYEL << " *** Human A attacks *** " << RES << std::endl;
	HumanA isabel("Isabel", sword);
	isabel.attack();

	std::cout << BYEL << " *** Human A changes weapon and attacks *** " << RES << std::endl;
	sword.setType("gun");
	isabel.attack();

	std::cout << BYEL << " *** Creating Human B *** " << RES << std::endl;
	Weapon x_weapon("knife");
	HumanB filipe("Filipe");
	std::cout << BYEL << " *** Human B tries to attack *** " << RES << std::endl;
	filipe.attack();
	std::cout << BYEL << " *** Human B gets a weapon and attacks *** " << RES << std::endl;
	filipe.setWeapon(x_weapon);
	filipe.attack();
	std::cout << BYEL << " *** Human B changes weapon and attacks *** " << RES << std::endl;
	x_weapon.setType("bow and arrow");
	filipe.setWeapon(x_weapon);
	filipe.attack();
}

/*
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
*/