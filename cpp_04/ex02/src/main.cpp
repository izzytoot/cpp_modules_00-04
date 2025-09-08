/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/23 11:28:17 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main(){
	std::cout << std::endl
		  << BCYA
		  << "************************ Creating new cat ************************"
		  << RES << std::endl << std::endl;
		  
	AAnimal* cat = new Cat();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << std::endl;
	delete cat;
	
	std::cout << std::endl
		  << BCYA
		  << "************************ Creating new dog ************************"
		  << RES << std::endl << std::endl;
	AAnimal* dog = new Dog();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << std::endl;
	delete dog;
	
	std::cout << std::endl
          << BCYA
          << "************************ Trying to create an abstract AAnimals ************************"
          << RES << std::endl 
		  << "Uncomment main.cpp to check." 
		  << std::endl;
	 //AAnimal dog;
	 //AAnimal* aanimal = new AAnimal();

	std::cout << std::endl;
	return 0;
}
