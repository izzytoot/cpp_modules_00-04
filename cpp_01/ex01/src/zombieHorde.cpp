/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 12:43:53 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		std::ostringstream fullName;
		fullName << name << (i + 1);
		horde[i].setName(fullName.str());
		horde[i].announce();
	}
	return horde;
}