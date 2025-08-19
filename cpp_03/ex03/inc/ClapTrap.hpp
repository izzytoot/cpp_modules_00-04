/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:41:29 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/19 14:35:49 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class ClapTrap{
	private:
		std::string _name;
		int _hit;
		int _energy;
		int _damage;

	protected:
		void setHit(int val);
		void setEnergy(int val);
		void setDamage(int val);
		void setName(std::string str);

	public:
		ClapTrap(); //default constructor
		ClapTrap(std::string name); //constructor with name
		ClapTrap(const ClapTrap& src); //copy constructor
		
		ClapTrap& operator= (const ClapTrap& src); //copy assignment operator
		
		~ClapTrap(); //destructor

		std::string getName() const;
		int getHit() const;
		int getEnergy() const;
		int getDamage() const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

#endif