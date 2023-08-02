/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:58:37 by tyi               #+#    #+#             */
/*   Updated: 2022/06/01 19:17:05 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_y(int *y)
{
	int		i;
	char	ch;

	i = -1;
	while (++i < 10)
	{
		ch = y[i] + 48;
		write (1, &ch, 1);
	}
	write(1, "\n", 1);
}

int	no_queen(int x, int *y)
{
	int	i;

	i = 0;
	while (i < x)
	{	
		if (y[i] == y[x])
			return (0);
		if (x - i == y[i] - y[x])
			return (0);
		if (i - x == y[i] - y[x])
			return (0);
		i ++;
	}
	return (1);
}

void	queen(int *cnt, int *y, int x)
{
	if (x == 10)
	{
		print_y(y);
		*cnt += 1;
	}
	else
	{
		y[x] = -1;
		while (++y[x] < 10)
		{
			if (no_queen(x, y))
				queen(cnt, y, x + 1);
			else
				continue ;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	y[10];

	cnt = 0;
	queen(&cnt, y, 0);
	return (cnt);
}
