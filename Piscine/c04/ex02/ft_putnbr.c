/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:19:39 by tyi               #+#    #+#             */
/*   Updated: 2022/05/31 12:42:43 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(unsigned int nb)
{
	char	m;

	if (nb >= 10)
		recur(nb / 10);
	m = nb % 10 + '0';
	write(1, &m, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		recur(-nb);
	}
	else
		recur(nb);
}
