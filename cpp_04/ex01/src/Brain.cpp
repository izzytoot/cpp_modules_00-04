/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:14:55 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/22 18:29:38 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

Brain::Brain(){
	for(int i = 0; i < 100; i++)
		_ideas[i] = "";
	std::cout << BGRN
		  	  << "A new Brain full of empty ideas was constructed."
			  << RES << std::endl;
}

Brain::Brain(const Brain& src){
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << BGRN
			  << "A Brain was copied and constructed."
			  << RES << std::endl;
}

Brain::~Brain(){
	std::cout << BRED
			  << "Brain was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Brain& Brain::operator= (const Brain& src){
	if (this != &src){
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << BYEL
			  << "Brain was copied into existing Brain."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

void Brain::setIdeas(int nb, std::string idea){
	std::cout << BYEL
			  << "Setting a new idea..."
			  << RES << std::endl;
	if(nb < 0 || nb > 99){
		std::cout << BRED
			  << "Error: Idea number not valid."
			  << RES << std::endl;
	}
	else{
		this->_ideas[nb] = idea;
		std::cout << "Idea number " << nb 
				  << " was set to: " << idea << "."
				  << std::endl;
	}	
}

std::string Brain::getIdea(int nb) const{
	std::cout << BYEL
			  << "Getting an idea from Brain..."
			  << RES << std::endl;
	if(nb < 0 || nb > 99){
		std::cout << BRED
			  << "Error: Idea number not valid."
			  << RES << std::endl;
		return "";
	}
	else{
		std::cout << "Idea number " << nb 
				  << " is: ";
	}
	return this->_ideas[nb];
}