/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:36:00 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/26 13:20:04 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria{
    public:
        Cure();
        Cure(const Cure& src);

        Cure& operator= (const Cure& src);

        ~Cure();
        
        AMateria* clone()const;
        void use(ICharacter& target);
};

#endif