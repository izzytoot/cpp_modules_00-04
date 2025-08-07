/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump_commented.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/07 12:35:59 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/*******************************************************************/
/*                        Helper function                          */
/*******************************************************************/

//Creates a zombie on the stack memory, announces it, and lets it die automatically:
//Stack allocated memory calls the destructor automatically
//allocated memory is destroyed automatically at the end of function - can't be used anymore
void randomChump( std::string name ){
	Zombie z(name);
	z.announce();
}
