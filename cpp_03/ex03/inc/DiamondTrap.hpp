/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:41:29 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 12:03:51 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//class declaration defines what DiamondTrap inherits from.
//DiamondTrap is a FragTrap and ScavTrap.
//public FragTrap and public ScavTrap are the base classes for DiamondTrap
class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string _name;
		
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		
		DiamondTrap& operator= (const DiamondTrap& src);
		
		~DiamondTrap();

		void attack(std::string target);
		void whoAmI();
		std::string printName();
};

#endif