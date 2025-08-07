/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/06 18:26:07 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// allocates N zombies on the heap memory using new >Zombie[N]
// must delete each zombie in main
Zombie* zombieHorde(int N, std::string name){
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N]; //default constructor
	for (int i = 0; i < N; i++){
		std::ostringstream fullName;
		fullName << name << (i + 1);
		horde[i].setName(fullName.str()); //sets name for each Zombie
		horde[i].announce(); //announces each Zombie
	}
	return horde; //returns pointer for first zombie in array
}