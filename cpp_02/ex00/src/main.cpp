/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:18 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/12 18:19:04 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a; //creates Fixed obj a
	Fixed b( a ); //copies a into new Fixed obj b
	Fixed c; //creates Fixed obj c
	
	c = b; //calls copy assignment to copy b into c

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}