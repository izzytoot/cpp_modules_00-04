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

int main(){
	Zombie	*firstZombie;
	Zombie	*secondZombie;

	firstZombie = newZombie("Isabel");
	firstZombie->announce();

	secondZombie = newZombie("Filipe");
	secondZombie->announce();

	return 0;
}