/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/01 18:06:51 by icunha-t         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/Zombie.hpp"

Zombie* newZombie(std::string name){
	Zombie* newZombie = new Zombie(name);
	return newZombie;
}