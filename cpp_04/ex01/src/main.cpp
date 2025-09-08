/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:43:25 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/23 11:21:36 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main(){
	std::cout << std::endl
		  << BCYA
		  << "************************ Subject tests ************************"
		  << RES << std::endl << std::endl;
	
	std::cout << BYEL
		  << " ---- New object: Dog ----"
		  << RES << std::endl;
	const Animal* j = new Dog();
	
	std::cout << BYEL
		  << " ---- New object: Cat ----"
		  << RES << std::endl;
	const Animal* i = new Cat();

	std::cout <<std::endl
		  << CYA
		  << "deleting Cat: "
		  << RES << std:: endl;
	delete j;
	
	std::cout <<std::endl
		  << CYA
		  << "deleting Dog: "
		  << RES << std:: endl;
	delete i;
	
	std::cout <<std::endl
		  	  << CYA
		 	  << "Creating array of 4 animals: 2 cats and 2 dogs"
		  	  << RES << std:: endl;
	Animal* animals[4];
	for (int i = 0; i < 2; i++){
		animals[i] = new Cat();
		std::cout << "----------" << std::endl;	
	}
	for (int i = 2; i < 4; i++){
		animals[i] = new Dog();
		std::cout << "----------" << std::endl;	
	}
		
	std::cout <<std::endl
		  	  << CYA
		 	  << "Deleting array of animals"
		  	  << RES << std:: endl;
	for (int i = 0; i < 4; i++){
		delete animals[i];
		std::cout << "----------" << std::endl;	
	}
		
	std::cout << std::endl
		  << BCYA
		  << "************************ More tests ************************"
		  << RES << std::endl << std::endl;
	
	std::cout <<std::endl
		  	  << CYA
		 	  << "Creating Cat Sushi"
		  	  << RES << std:: endl;
	Cat sushi;

	std::cout <<std::endl
		  	  << CYA
		 	  << "Setting and getting an idea"
		  	  << RES << std:: endl;
	sushi.getBrain()->setIdeas(-5, "Invalid");
	sushi.getBrain()->setIdeas(50, "My name is Sushi");
	std::cout <<std::endl;
	sushi.getBrain()->getIdea(-5);
	std::cout << sushi.getBrain()->getIdea(50) << ".";
	std::cout <<std::endl;

	std::cout <<std::endl
		  	  << CYA
		 	  << "Creating Cat Quiwi with Copy Constructor from Sushi"
		  	  << RES << std:: endl;
	Cat quiwi(sushi);

	std::cout <<std::endl
		  	  << CYA
		 	  << "Getting Quiwi's idea number 50"
		  	  << RES << std:: endl;
	std::cout << quiwi.getBrain()->getIdea(50) << ".";
	std::cout <<std::endl
		  	  << CYA
		 	  << "Changing Quiwi's idea number 50"
		  	  << RES << std:: endl;
	quiwi.getBrain()->setIdeas(50, "My name is Quiwi");
	std::cout << std::endl << CYA 
			  << "Quiwi's 50th idea:" 
			  << std::endl
			  << quiwi.getBrain()->getIdea(50) << ".";
	std::cout << std::endl << CYA 
			  << "Sushi's 50th idea: " 
			  <<std::endl
			  << sushi.getBrain()->getIdea(50) << ".";
	
	std::cout <<std::endl <<std::endl
		  	  << BCYA
		 	  << "Now with Dogs: Jack copied into Santiago"
		  	  << RES << std:: endl;
	std::cout <<std::endl
		  	  << CYA
		 	  << "Dog Jack:"
		  	  << RES << std:: endl;
	Dog jack;
	std::cout <<std::endl;
	jack.getBrain()->setIdeas(1, "Let's run!!!");

	std::cout <<std::endl
		  	  << CYA
		 	  << "Dog Santiago:"
		  	  << RES << std:: endl;
	Dog santiago(jack);
	std::cout <<std::endl;
	jack.getBrain()->setIdeas(1, "Better not, Filipe will get angry...");

	std::cout <<std::endl
			  << "Jack idea 1: " 
			  << std::endl
			  << jack.getBrain()->getIdea(1) << std::endl;
	std::cout <<std::endl
			  << "Santiago idea 1: " 
			  << std::endl
			  << santiago.getBrain()->getIdea(1) << std::endl;
	
	
	std::cout <<std::endl;
	return 0;
}
