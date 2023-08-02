/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:27:53 by tyi               #+#    #+#             */
/*   Updated: 2022/05/24 22:01:21 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(unsigned int nbr)
{
	int	mod;

	if (nbr < 10)
	{
		nbr = nbr + 48;
		write(1, &nbr, 1);
	}
	else
	{	
		put_nbr(nbr / 10);
		mod = nbr % 10 + 48;
		write(1, &mod, 1);
	}
}

void	toplus(unsigned int nbr)
{
	put_nbr(nbr);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{	
		write(1, "-", 1);
		toplus(-nb);
	}
	else
		toplus(nb);
}
