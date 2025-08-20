/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:41:29 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/20 17:51:44 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//class declaration defines what DiamondTrap inherits from.
//DiamondTrap is-a FragTrap and ScavTrap.
//public FragTrap and public ScavTrap are the base classes for DiamondTrap
class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string _name; //DiamondTrap::_name (Diamond's identity)
		
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