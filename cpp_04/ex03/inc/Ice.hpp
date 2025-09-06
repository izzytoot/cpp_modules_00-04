/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:34:43 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/08/26 13:27:24 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria{
    public:
        Ice();
        Ice(const Ice& src);

        Ice& operator= (const Ice& src);

        ~Ice();

        AMateria* clone()const;
        void use(ICharacter& target);
};

#endif