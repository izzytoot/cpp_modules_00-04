/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:50:38 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/29 14:36:41 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream> //for cout and cin 
#include <cstring> //for toupper

//std:: - standard format 
//cout - content on output (printf)
//endl - new line
int main(int ac, char **av)
{
	int i, j;
	
	if (ac < 2) //if no args print error message
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		i = 0;
		while(av[++i])
		{
			j = -1;
			while(av[i][++j])
				std::cout << (char)toupper(av[i][j]); //transform lowercase in uppercase
			if (i < ac - 1) //space between args except for last
				std::cout << " ";
		}
		std::cout << std::endl; //new line
	}
	return (0);
}