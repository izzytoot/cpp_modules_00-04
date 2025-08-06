/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/06 19:13:24 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iomanip>
#include <iostream>

class Weapon{
	private:
		std::string _type;
		
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const; //first const protects return value; second const guarantees the function can't change value inside
		void setType(const std::string& newType); //& passes the string without copying it
};

#endif