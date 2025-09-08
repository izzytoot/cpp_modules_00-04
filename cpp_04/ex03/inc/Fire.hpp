/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:02 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/08 12:53:24 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

#include "AMateria.hpp"

class Fire: public AMateria{
    public:
        Fire();
        Fire(const Fire& src);

        Fire& operator= (const Fire& src);

        ~Fire();

        AMateria* clone()const;
        void use(ICharacter& target);
};

#endif