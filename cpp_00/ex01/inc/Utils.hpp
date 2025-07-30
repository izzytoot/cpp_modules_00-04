/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:28:47 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/30 18:29:13 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <signal.h>
#include <limits>
#include <cstdlib>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

#define EXIT_ON_EOF if (std::cin.eof()) { \
    std::cout << std::endl << RED << "EOF received. Exiting program. ❌" << RES << std::endl; \
    std::exit(0); \
}

#endif