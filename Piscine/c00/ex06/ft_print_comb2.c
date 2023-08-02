/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:19:13 by tyi               #+#    #+#             */
/*   Updated: 2022/05/23 19:16:37 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int a, int b)
{
	int	str[5];
	int	n;

	n = 0;
	str[0] = a / 10 + 48;
	str[1] = a % 10 + 48;
	str[2] = ' ';
	str[3] = b / 10 + 48;
	str[4] = b % 10 + 48;
	while (n < 5)
	{
		write(1, str + n, 1);
		n ++;
	}
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			print_comb(a, b);
			b ++;
		}
		a ++;
	}
}
