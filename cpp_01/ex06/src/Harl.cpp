/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:58:10 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/11 20:02:03 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

Harl::Harl(){}

Harl::~Harl(){}

/*******************************************************************/
/*                     Private member functions                    */
/*******************************************************************/

void Harl::debug(){
	std::cout << BGRN << "[DEBUG]" << std::endl
			  << "This is Harl's DEBUG complaint!" << RES
			  << std::endl;
}

void Harl::info(){
	std::cout << BCYA << "[INFO]" << std::endl
			  << "This is Harl's INFO complaint!" << RES
			  << std::endl;
}

void Harl::warning(){
	std::cout << BYEL << "[WARNING]" << std::endl
			  << "This is Harl's WARNING complaint!" << RES
			  << std::endl;
}

void Harl::error(){
	std::cout << BRED << "[ERROR]" << std::endl
			  << "This is Harl's ERROR complaint!" << RES
			  << std::endl;
}

/*******************************************************************/
/*                      Public member functions                    */
/*******************************************************************/

void Harl::complain(std::string level){
	int intLevel = strLevelToInt(level);

	switch(intLevel){
		case 0:
			debug();
			std::cout << std::endl;
		case 1:
			info();
			std::cout << std::endl;
		case 2:
			warning();
			std::cout << std::endl;
		case 3:
			error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;		
	}
}

/*******************************************************************/
/*                        Helper functions                         */
/*******************************************************************/

int strLevelToInt(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int intLevel[4] = {0, 1, 2, 3};

	for (int i = 0; i < 4; i++){
		if (level == levels[i])
			return intLevel[i];
	}

	return -1;
}