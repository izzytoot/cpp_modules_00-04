/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:18 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 17:10:35 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a; //default constr.
	Fixed b(a); //copy constr. (calls copy assignm. and getRawBits) 
	Fixed c; //default constr.
	
	c = b; //copy assignm. (calls getRawBits)
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}