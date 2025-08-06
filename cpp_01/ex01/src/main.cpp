/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/06 18:25:57 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(){
	int n = 5;

	std::cout << BCYA << "Creating the Horde..." << RES << std::endl;
	Zombie *horde = zombieHorde(n, "Hoardy_");

	std::cout << BCYA << "Destroying the Horde..." << RES << std::endl;
	delete[] horde;

	return (0);
}
