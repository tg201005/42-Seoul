/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:24:06 by tyi               #+#    #+#             */
/*   Updated: 2023/05/24 22:45:49 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main (int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
                std::cout <<  static_cast<char>(std::toupper(av[i][j]));
        }
        std::cout << std::endl;
    }
}