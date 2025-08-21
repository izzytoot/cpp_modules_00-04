/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/21 18:11:56 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
std::cout << std::endl
		  << BCYA
		  << "************************ Subject tests ************************"
		  << RES << std::endl << std::endl;

std::cout << BYEL
		  << " ---- New object: Animal meta ----"
		  << RES << std::endl;
const Animal* meta = new Animal();

std::cout << std::endl
		  << BYEL
		  << " ---- New object: Dog j ----"
		  << RES << std::endl;
const Animal* j = new Dog();

std::cout << std::endl
		  << BYEL
		  << " ---- New object: Cat i ----"
		  << RES << std::endl;
const Animal* i = new Cat();

std::cout << std::endl
		  << BYEL
		  << " ---- Testing getType() ----"
		  << RES << std::endl;
		  
std::cout << CYA
		  << "for Dog j, type is: "
		  << RES;
std::cout << j->getType() << " " << std::endl;
std::cout << CYA
		  << "for Cat i, type is: "
		  << RES;
std::cout << i->getType() << " " << std::endl;

std::cout << std::endl
		  << BYEL
		  << " ---- Testing makeSound() ----"
		  << RES << std::endl;

std::cout << CYA
		  << "for Cat i, sound is: "
		  << RES;
i->makeSound();
std::cout << CYA
		  << "for Dog j, sound is: "
		  << RES;	
j->makeSound();
std::cout << CYA
		  << "for Animal meta, sound is: "
		  << RES;	
meta->makeSound();

std::cout <<std::endl
		  << CYA
		  << "deleting Animal meta: "
		  << RES << std:: endl;
delete meta;
std::cout <<std::endl
		  << CYA
		  << "deleting Cat i: "
		  << RES << std:: endl;
delete i;
std::cout <<std::endl
		  << CYA
		  << "deleting Dog j: "
		  << RES << std:: endl;
delete j;

std::cout << std::endl
		  << BCYA
		  << "************************ WrongAnimal tests ************************"
		  << RES << std::endl << std::endl;

std::cout << BYEL
		  << " ---- New object: WrongAnimal ----"
		  << RES << std::endl;
const WrongAnimal* wrong = new WrongAnimal();

std::cout << std::endl
		  << BYEL
		  << " ---- New object: WrongCat ----"
		  << RES << std::endl;
const WrongAnimal* wrongCat = new WrongCat();

std::cout << std::endl
		  << BYEL
		  << " ---- Testing getType() ----"
		  << RES << std::endl;
		  
std::cout << CYA
		  << "for WrongCat, type is: "
		  << RES;
std::cout << wrongCat->getType() << " " << std::endl;

std::cout << std::endl
		  << BYEL
		  << " ---- Testing makeSound() ----"
		  << RES << std::endl;

std::cout << CYA
		  << "for WrongCat, sound is: "
		  << RES;	
wrongCat->makeSound();

std::cout << CYA
		  << "for WrongAnimal, sound is: "
		  << RES;
wrong->makeSound();

std::cout <<std::endl
		  << CYA
		  << "deleting WrongCat: "
		  << RES << std:: endl;
delete wrongCat;
std::cout <<std::endl
		  << CYA
		  << "deleting WrongAnimal: "
		  << RES << std:: endl;
delete wrong;

return 0;
}