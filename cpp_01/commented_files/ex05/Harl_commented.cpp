/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 15:29:00 by icunha-t         ###   ########.fr       */
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
	std::cout << BGRN << "This is Harl's DEBUG complaint!" << RES << std::endl;
}

void Harl::info(){
	std::cout << BCYA << "This is Harl's INFO complaint!" << RES << std::endl;
}

void Harl::warning(){
	std::cout << BYEL << "This is Harl's WARNING complaint!" << RES << std::endl;
}

void Harl::error(){
	std::cout << BRED << "This is Harl's ERROR complaint!" << RES << std::endl;
}

/*******************************************************************/
/*                      Public member functions                    */
/*******************************************************************/

//2 arrays: one with the level strings, one with the correspondigng ft pointers
//arr1 "DEBUG" ; arr2 &Harl::debug
//loop to find match
//when match found, call the function ptr (this->*functionPointers[i]())

void Harl::complain(std::string level){
	//array of 4 strings
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	//this array stores the memory addresses of Harl's private functions
	//parenthisis guarantees that it's an array of ptrs to member fts
	void (Harl::*ftPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level.empty()){
		std::cout << RED << "Error: empty level!" << RES << std::endl;
		return ;	
	}
	
	//looks for match in the 1st array
	//when found, executes correspondant ptr
	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*ftPtr[i])(); //ptrs to member functions have to come from an object (this)
			return ;
		}
	}
	std::cout << RED << "Error: level not found!" << RES << std::endl;
}