/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:43 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/29 18:15:33 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(){
	std::string input;
	PhoneBook book;
	
	std::cout << "Welcome to My Awsome Phonebook!" << std::endl;
	std::cout << "To add a new contact type in ADD" << std::endl;
	std::cout << "To search for a contact type in SEARCH" << std::endl;
	std::cout << "To exit the program type in EXIT" << std::endl;
		
	while(1){
		if (!std::getline(std::cin, input)){
			std::cout << "No input: exiting My Awsome Phonebook" << std::endl;
			return 0;
		}
		if (input == "ADD")
			book.addContact();
		else if(input == "SEARCH")
			book.searchContact();
		else if(input == "EXIT"){
			std::cout << "Exiting My Awsome Phonebook" << std::endl;
			return 0;
		}
		else
			std::cout << "Wrong input. Choose ADD, SEARCH, or EXIT" <<std::endl;
	}
	return 0;
}