/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 16:54:20 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(){
	int n = 5;

	std::cout << BCYA << "Testing with invlid N..." << RES << std::endl;
	Zombie *invHorde = zombieHorde(-5, "Hoardy_");
	delete[] invHorde;
	
	std::cout << BCYA << "Creating the Horde..." << RES << std::endl;
	Zombie *horde = zombieHorde(n, "Hoardy_");

	std::cout << BCYA << "Destroying the Horde..." << RES << std::endl;
	delete[] horde;

	return (0);
}
