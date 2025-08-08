/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 17:09:38 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>

#define BCYA "\033[36;1m"
#define RES "\033[0m"

int main(){
	std::string stringSTR = "HI THIS IS BRAIN";
	
	std::string* stringPTR = &stringSTR;
	std::string& stringREF = stringSTR;

	std::cout << BCYA << "*** MEMORY ADDRESSES ***" << RES << std::endl;
	std::cout <<  "stringSTR: " << &stringSTR << std::endl;
	std::cout <<  "stringPTR: " << stringPTR << std::endl;
	std::cout <<  "stringREF: " << &stringREF << std::endl;

	std::cout << BCYA << "*** VALUES ***" << RES << std::endl;
	std::cout <<  "stringSTR: " << stringSTR << std::endl;
	std::cout <<  "stringPTR: " << *stringPTR << std::endl;
	std::cout <<  "stringREF: " << stringREF << std::endl;

	return 0;
}
