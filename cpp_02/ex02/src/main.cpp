/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:04:03 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 20:00:38 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main(void) {
	Fixed a; //default constr
	Fixed const b(Fixed(5.05f) * Fixed(2)); //10.1
	
	std::cout << GRN"a is "RES << a << std::endl;
	std::cout << GRN"a after pre increment is "RES << ++a << std::endl; //pre incr a
	std::cout << GRN"a is still "RES << a << std::endl;
	std::cout << GRN"a after post increment is still "RES << a++ << std::endl; //post incr a
	std::cout << GRN"now a is "RES << a << std::endl;
	
	std::cout << std::endl << RED"a is "RES << a << std::endl;
	std::cout << RED"a after pre decrement is "RES << --a << std::endl; //pre incr a
	std::cout << RED"a is still "RES << a << std::endl;
	std::cout << RED"a after post decrement is still "RES << a-- << std::endl; //post incr a
	std::cout << RED"now a is "RES << a << std::endl;
	
	std::cout << std::endl << YEL"a is "RES << a << std::endl;
	std::cout << YEL"b is "RES << b << std::endl;
	std::cout << YEL"max is "RES << Fixed::max( a, b ) << std::endl;
	std::cout << YEL"min is "RES << Fixed::min( a, b ) << std::endl;
	return 0;
}
