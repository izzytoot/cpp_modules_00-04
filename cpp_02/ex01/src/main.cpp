/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:39 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/14 18:49:03 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main(){
	Fixed a; //default constr
	Fixed const b(10); //int constr
	Fixed const c(42.42f); //float constr
	Fixed const d(b); //copy constr (calls copy assignm)
	
	a = Fixed(1234.4321f); //float constr + copy assign
	
	std::cout << std::endl << "a is " << a << std::endl; //1234.43
	std::cout << "b is " << b << std::endl; //10
	std::cout << "c is " << c << std::endl; //42.4219 ; the 19 comes from converting raw kept in FPV back 
	std::cout << "d is " << d << std::endl << std::endl; //10
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl << std::endl;

	return 0;
}
