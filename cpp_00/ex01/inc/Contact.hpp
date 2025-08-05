/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:12:22 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/30 18:29:49 by icunha-t         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <signal.h>
#include <limits>
#include <cstdlib>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Contact{

	public :
		Contact();
		~Contact();
		
		std::string getfname() const;
		std::string getlname() const;
		std::string getnname() const;
		std::string getphone() const;
		std::string getsecr() const;

		void setfname(std::string str);
		void setlname(std::string str);
		void setnname(std::string str);
		void setphone(std::string str);
		void setsecr(std::string str);

	private:
		std:: string first_name;
		std:: string last_name;
		std:: string nickname;
		std:: string phone_number;
		std:: string darkest_secret;
};

#endif