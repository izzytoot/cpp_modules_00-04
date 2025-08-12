/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:58:20 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 16:29:13 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << RED << "Error: Run ./harlFilter <level of complaint>" << RES << std::endl;
		return 1;
	}
	
	std::string level = av[1];
	if (level.empty()){
		std::cout << RED << "Error: level can't be empty!" << RES << std::endl;
		return 1;
	}
		
	Harl harl;
	harl.complain(level);
	
	return 0;
}
