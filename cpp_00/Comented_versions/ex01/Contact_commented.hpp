/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:12:22 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/30 18:29:49 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Utils.hpp"

class Contact{
	//public data and methods can be accessed and changed from outside the Contact class
	//these methods are how we set and change data
	//Contact c + c.setfname("Isabel");
	public :
		Contact(); //constructor
		~Contact(); //destructor
		
		//getter methods - return a private attribute (read only)
		std::string getfname() const;
		std::string getlname() const;
		std::string getnname() const;
		std::string getphone() const;
		std::string getsecr() const;

		//setter methods - assign a value to the private attribute (write-only)
		void setfname(std::string str);
		void setlname(std::string str);
		void setnname(std::string str);
		void setphone(std::string str);
		void setsecr(std::string str);
	
	//private data and methods can't be accessed outside the Contact class 	
	//XXX Contact c + c.first_name = Isabel XXX;
	private:
		std:: string first_name;
		std:: string last_name;
		std:: string nickname;
		std:: string phone_number;
		std:: string darkest_secret;
};

#endif