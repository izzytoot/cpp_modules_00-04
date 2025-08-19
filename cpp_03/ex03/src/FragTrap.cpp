/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/19 17:23:45 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

/******************************************************************************/
/*                  Constructor, Copy Constructor, Destructor                 */
/******************************************************************************/
FragTrap::FragTrap(): ClapTrap() {
	setName("to be named");
	setHit(100);
	setEnergy(100);
	setDamage(30);
	std::cout << BGRN 
			  << "Nameless FragTrap was constructed." 
			  << RES << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	setHit(100);
	setEnergy(100);
	setDamage(30);
	std::cout << BGRN 
			  << "FragTrap " 
			  << name 
			  << " was constructed." 
			  << RES << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src) {
	std::cout << BGRN
			  << "FragTrap "
			  << src.getName() 
			  << " was constructed and copied." 
			  << RES << std::endl;
}
				
FragTrap::~FragTrap(){
	if (getName() != "to be named"){
		std::cout << BRED 
				  << "FragTrap " 
				  << getName() 
				  << " was destroyed." 
				  << RES << std::endl;

	}
	else{
		std::cout << BRED 
				 << "Nameless FragTrap was destroyed." 
				 << RES << std::endl;
	}
}
/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

FragTrap& FragTrap::operator= (const FragTrap& src){
	std::cout << BYEL 
			  << "FragTrap "
			  << src.getName() 
			  << " was and copied into existing FragTrap." 
			  << RES << std::endl;
	if (this != &src)
		FragTrap::operator=(src);
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void	FragTrap::highFivesGuys(){
	std::cout << "🙌 give me a high-five!! 🙌"
			  << " , said "
			  << this->getName()
			  << std::endl;
}