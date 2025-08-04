/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:01:31 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:13:28 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//what addContact() should do:
//ask the user for 5 inputs: First name, Last name, Nickname, Phone number, Darkest secret
//validate the input
//store the contact in contacts[]
//overwrite the last content if > 8
#include "PhoneBook.hpp"

/* *************************************************************** */
/*                               Macros                            */
/* *************************************************************** */

#define EXIT_ON_EOF if (std::cin.eof()) { \
    std::cout << std::endl << RED << "EOF received. Exiting program. ❌" << RES << std::endl; \
    std::exit(0); \
}

/* *************************************************************** */
/*                               Utils                             */
/* *************************************************************** */

//checks if the input has only digits
int	onlyNumbers(std::string str){
	for(int i = 0; i < (int)str.length(); i++){
		if(!std::isdigit(str[i]) && !std::isspace(str[i]))
			return 1;
	}
	return 0;
}

//trims off the spaces before and after the word. If only spaces - empty
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

std::string dispField(std::string content){
	if(content.length() > 10)
		return (content.substr(0, 9) + ".");
	return (content);
}

int isAllDigits(const std::string& str) 
{
    for (std::string::size_type i = 0; i < str.length(); i++) 
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return 0;
    }
    return 1;
}

/* *************************************************************** */
/*                    Constructor and Destructor                   */
/* *************************************************************** */

PhoneBook:: PhoneBook() : index(0), counter(0) {}
PhoneBook:: ~PhoneBook(){}

/* *************************************************************** */
/*                             Methods                             */
/* *************************************************************** */

void PhoneBook::addContact(){
	Contact new_contact;
	
	std::cout << std::endl;
	// Get user input for each field. Use parseInput to request and check valid input.
	new_contact.setfname(parseInput("First Name")); //const char * -> std::string temporary
	new_contact.setlname(parseInput("Last Name"));
	new_contact.setnname(parseInput("Nickname"));
	new_contact.setphone(parseInput("Phone Number"));
	new_contact.setsecr(parseInput("Darkest Secret"));

	//update index and counter
	index = (index) % 8; //check if index is above 8. circular buffer trick
	
	//save in buffer and overwrite the last one after 8 contacts
	contacts[index] = new_contact;
	index++;
	
	if (counter < 8)
		counter++;
	std::cout << GRN << std::endl << "Success! New contact added. ✅" << RES << std::endl;
	return ;
}

void PhoneBook::searchContact(){
	std::string chosen_nb_s;
	int chosen_nb_int;
	int flag = 0;
	//if empty
	if (counter == 0){
		std::cout << RED << "PhoneBook is empty. Please ADD a new contact." << RES << std::endl;
		return ;
	}

	//display PB header
	std::cout << BCYA << std::endl << " __________ __________ __________ __________ " << RES << std::endl;
	std::cout << BCYA << "|          |          |          |          |" << RES << std::endl;
	std::cout << BCYA << "|     Index|First Name| Last Name|  Nickname|" << RES << std::endl;
	std::cout << BCYA << "|__________|__________|__________|__________|" << RES << std::endl;
	//display PB contacts
	//set colums to 10chars wide and print fields
	for (int i = 0; i < counter; i++){
		std::cout << BCYA "|" RES  << std::setw(10) << i + 1;
		std::cout << BCYA "|" RES << std::setw(10) << std::right << dispField(contacts[i].getfname());
		std::cout << BCYA "|" RES << std::setw(10) << std::right << dispField(contacts[i].getlname());
		std::cout << BCYA "|" RES << std::setw(10) << std::right << dispField(contacts[i].getnname());
		std::cout << BCYA "|" RES << std::endl;
	}
	std::cout << BCYA << "|__________|__________|__________|__________|" << RES << std::endl;
	while (true){
		if (flag == 0){
			std::cout << std::endl << YEL << "Type an index number for more info or BACK for main menu." << RES << std::endl;	
		}
		std::getline(std::cin, chosen_nb_s);
		EXIT_ON_EOF;
		flag = 0;
		if (chosen_nb_s == "BACK"){
			std::cout << std::endl;
			break ;
		}
		if (!isAllDigits(chosen_nb_s)){
			std::cout << RED << "Index must be a number between 1 and " << counter << "." << RES << std::endl;
			flag = 1;
		}
		else{
			chosen_nb_int = std::atoi(chosen_nb_s.c_str());
			if (chosen_nb_s.length() != 1 || !isdigit(chosen_nb_s[0]) || chosen_nb_int < 1 || chosen_nb_int > counter){
				std::cout << RED << "Index must be a number between 1 and " << counter << "." << RES << std::endl;
				flag = 1;	
			}
			else{
				std::cout << BCYA "First name: " RES << contacts[chosen_nb_int - 1].getfname() << std::endl;
				std::cout << BCYA "Last name: " RES << contacts[chosen_nb_int - 1].getlname() << std::endl;
				std::cout << BCYA "Nickname: " RES << contacts[chosen_nb_int - 1].getnname() << std::endl;
				std::cout << BCYA "Phonenubmer: " RES << contacts[chosen_nb_int - 1].getphone() << std::endl;
				std::cout << BCYA "Darkest secret: " RES << contacts[chosen_nb_int - 1].getsecr() << std::endl;	
			}	
		}
	}
	return ;
}