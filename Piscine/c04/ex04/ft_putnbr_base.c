/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:12:20 by tyi               #+#    #+#             */
/*   Updated: 2022/05/31 12:37:24 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_strl(unsigned int nbr, char *base, unsigned int l)
{
	if (nbr >= l)
		to_strl(nbr / l, base, l);
	write(1, base + (nbr % l), 1);
}

int	check_same(char *base, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (base[i] == base[j])
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;

	l = -1;
	while (base[++l])
	{
		if (base[l] == '-' || base[l] == '+')
			return ;
	}
	if (l < 2)
		return ;
	if (check_same(base, l))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_strl(-nbr, base, l);
	}
	else
		to_strl(nbr, base, l);
}
