/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 16:55:33 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	if (N <= 0){
		std::cout << RED << "Invalid number of zombies" << RES << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		std::ostringstream fullName;
		fullName << name << (i + 1);
		horde[i].setName(fullName.str());
		horde[i].announce();
	}
	return horde;
}