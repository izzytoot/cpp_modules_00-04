/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:01:31 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/30 19:05:00 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//what addContact() should do:
//ask the user for 5 inputs: First name, Last name, Nickname, Phone number, Darkest secret
//validate the input
//store the contact in contacts[]
//overwrite the last content if > 8
#include "PhoneBook.hpp"


//utils
int	onlyNumbers(std::string str){
	for(int i = 0; i < (int)str.length(); i++){
		if(std::isalpha(str[i]))
			return 1;
	}
	return 0;
}

std::string trim(const std::string& str){
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, last - first + 1);
}

std::string parseInput(const std::string& field){ //the & means wee're passing field by reference (avoids unnecessary copying)
	std::string input;	
	
	while (true){
		std::cout << BCYA << field << ": " << RES;
		
		std::getline(std::cin, input);
		EXIT_ON_EOF;
		
		input = trim(input);
		if (input.empty())
		{
			std::cout << RED << "Field can't be empty. Please write your " << field << "." << RES << std::endl;
			continue;
		}

		if(field == "Phone Number"){
			if(onlyNumbers(input)){
				std::cout << RED << "This field only accepts numbers. Try again." << RES << std::endl;
				continue;
			}
		}
		return input;
	}
}

//constructor and destructor
PhoneBook:: PhoneBook() : index(0), counter(0) {}
PhoneBook:: ~PhoneBook(){}

//methods
void PhoneBook::addContact(){
	Contact new_contact;
	
	std::cout << std::endl;
	// Get user input for each field. Use parseInput to request and check valid input.
	new_contact.setfname(parseInput("First Name")); //const char * -> std::string temporary
	if (new_contact.getfname() == "")
		return ;
	new_contact.setlname(parseInput("Last Name"));
	if (new_contact.getlname() == "")
		return ;
	new_contact.setnname(parseInput("Nickname"));
	if (new_contact.getnname() == "")
		return ;
	new_contact.setphone(parseInput("Phone Number"));
	if (new_contact.getphone() == "")
		return ;
	new_contact.setsecr(parseInput("Darkest Secret"));
	if (new_contact.getsecr() == "")
		return ;
		
	//save in buffer and overwrite the last one after 8 contacts
	contacts[index] = new_contact;

	//update index and counter
	index = (index + 1) % 8; //check if index is above 8. circular buffer trick
	if (counter < 8)
		counter++;
	std::cout << GRN << std::endl << "Success! New contact added. ✅" << RES << std::endl;
	return ;
}

void PhoneBook::searchContact(){
	
}