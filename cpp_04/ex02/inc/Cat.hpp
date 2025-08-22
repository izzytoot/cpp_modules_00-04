/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:48:44 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/22 18:59:45 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& src);

		Cat& operator= (const Cat& src);

		~Cat();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif