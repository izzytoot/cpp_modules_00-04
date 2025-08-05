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

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iomanip>
#include <iostream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class	Zombie{
	public:
		Zombie();
		~Zombie();

		Zombie(std::string newname); //why no type
		void announce(void);

	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void *randomChump(std::string name);

#endif