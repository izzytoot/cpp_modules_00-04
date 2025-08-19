/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:41:29 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/19 17:25:51 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//public ClapTrap means ScavTrap gets all public and protected members of ClapTrap.
//ScavTrap contains a ClapTrap inside
//ClapTrap constructor is called first

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		
		ScavTrap& operator= (const ScavTrap& src);
		
		~ScavTrap();

		void attack(std::string target);
		void guardGate();
};

#endif