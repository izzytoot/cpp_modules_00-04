/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB_commented.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 12:56:24 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

//weapon is optional (not defined in constructor) so it can start without a weapon
class HumanB{
	private:
		std::string _name;
		Weapon* _weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();
		
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif