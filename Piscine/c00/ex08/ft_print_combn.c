/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:14:59 by tyi               #+#    #+#             */
/*   Updated: 2022/06/01 13:04:18 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	recur(char *str, int n, int a)
{
	if (a == n)
	{
		write(1, str, n);
		if (str[0] != '0' + 10 - n)
			write(1, ", ", 2);
	}
	else
	{
		if (a > 0)
			str[a] = str[a - 1] + 1;
		else
			str[a]++;
		while (str[a] < '0' + 11 - n + a)
		{	
			recur(str, n, a + 1);
			str[a]++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	str[9];

	str[0] = '0' - 1;
	recur(str, n, 0);
}
