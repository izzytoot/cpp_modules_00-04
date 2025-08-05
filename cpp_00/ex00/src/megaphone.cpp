/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:50:38 by icunha-t          #+#    #+#             */
/*   Updated: 2025/07/29 15:01:47 by icunha-t         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <cstring>

/*******************************************************************/
/*                             Main                                */
/*******************************************************************/

int main(int ac, char **av)
{
	int i, j;
	
	if (ac < 2)
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
				std::cout << (char)toupper(av[i][j]);
			if (i < ac - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}