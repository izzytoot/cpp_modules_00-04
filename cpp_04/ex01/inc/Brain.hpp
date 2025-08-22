/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:02:30 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/22 18:26:09 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& src);
		
		Brain& operator= (const Brain& src);

		~Brain();

		void setIdeas(int nb, std::string idea);
		std::string getIdea(int nb) const;
};

#endif