/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/29 17:05:35 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//constructor and destructor
Contact:: Contact(){}
Contact:: ~Contact(){}

//getter methods(read)
std::string Contact::getfname()const{
	return(first_name);
}

std::string Contact::getlname()const{
	return(last_name);
}

std::string Contact::getnname()const{
	return(nickname);
}

std::string Contact::getphone()const{
	return(phone_number);
}

std::string Contact::getsecr()const{
	return(darkest_secret);
}

//setter methods (write)
void Contact::setfname(std::string str){
	first_name = str;
}

void Contact::setlname(std::string str){
	last_name = str;
}

void Contact::setnname(std::string str){
	nickname = str;
}

void Contact::setphone(std::string str){
	phone_number = str;
}

void Contact::setsecr(std::string str){
	darkest_secret = str;
}
