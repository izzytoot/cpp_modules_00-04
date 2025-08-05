/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:04:23 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:07:22 by icunha-t         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	public :
		PhoneBook();
		~PhoneBook();
		
		void addContact();
		void searchContact();

	private :
		Contact contacts[8];
		int index;
		int counter;
};

#endif