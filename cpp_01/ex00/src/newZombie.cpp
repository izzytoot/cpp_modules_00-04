/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/06 18:26:51 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/*******************************************************************/
/*                        Helper function                          */
/*******************************************************************/

//allocates on the heap memory using new and returns the pointer
//new is a keyword bultin to C++
//allocated memory can be used outside the scope of this function
Zombie* newZombie(std::string name){
	Zombie* newZombie = new Zombie(name);
	return newZombie;
}
