/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:47:41 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 18:59:48 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& src);

		Dog& operator= (const Dog& src);

		~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif