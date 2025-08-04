/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:43 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:09:02 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* *************************************************************** */
/*                            Macros                               */
/* *************************************************************** */

#define EXIT_ON_EOF if (std::cin.eof()) { \
    std::cout << std::endl << RED << "EOF received. Exiting program. ❌" << RES << std::endl; \
    std::exit(0); \
}

/* *************************************************************** */
/*                             Main                                */
/* *************************************************************** */

int main(){
	std::string input;
	PhoneBook book;
	
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	
	std::cout << std::endl << BGRN << "Welcome to My Awsome Phonebook! ☀️" << RES << std::endl;
	std::cout << YEL << "To add a new contact type in ADD." << std::endl;
	std::cout << "To search for a contact type in SEARCH." << std::endl;
	std::cout << "To exit the program type in EXIT." << RES << std::endl;

	while(true){
		std::getline(std::cin, input);
		EXIT_ON_EOF;                                                   
		if (input == "ADD")
		{
			book.addContact();
			std::cout << BYEL << "Main menu: " << YEL << "To continue type in ADD, SEARCH or EXIT." << RES << std::endl;
		}
		else if(input == "SEARCH"){
			book.searchContact();
			std::cout << BYEL << "Main menu: " << YEL << "To continue type in ADD, SEARCH or EXIT." << RES << std::endl;
		}
		else if(input == "EXIT"){
			std::cout << std::endl << BGRN << "Exiting My Awsome Phonebook. 👋" << RES << std::endl;
			break;
		}
		else
			std::cout << RED << "❌ Wrong input. Choose ADD, SEARCH, or EXIT." << RES << std::endl;
	}
	return 0;
}