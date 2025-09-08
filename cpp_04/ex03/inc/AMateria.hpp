/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:26:59 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/08 12:30:15 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "ICharacter.hpp"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class ICharacter; //informs that there is a type named ICharacter. We don't need the full definition

class AMateria{
    protected:
        const std::string _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& src);

        AMateria& operator= (const AMateria& src);

        virtual ~AMateria(); //for polymorphic deletion - clled after derived
    
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif