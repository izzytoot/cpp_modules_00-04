/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:04:23 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:07:22 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	public :
		PhoneBook(); //constructor
		~PhoneBook(); //destructor
		
		void addContact(); //to add a contact
		void searchContact(); //to search for contacts

	private :
		Contact contacts[8]; //max 8 contacts
		int index; //contact index to decide which contact to remove/get info // Points to where the next contact goes
		int counter; //contact counter (max 8)
};

#endif