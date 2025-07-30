/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:04:23 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/30 19:04:53 by icunha-t         ###   ########.fr       */
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
		Contact contacts[7]; //max 8 contacts
		int index; //contact index to decide which contact to remove/get info // Points to where the next contact goes
		int counter; //contact counter (max 8)
};

#endif