/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:02:56 by tyi               #+#    #+#             */
/*   Updated: 2022/05/29 17:11:47 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int a)
{
	char	b;

	if (a < 10)
	{
		b = '0' + a;
		write(1, &b, 1);
	}
	else
	{
		b = 'a' + a - 10;
		write(1, &b, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*s1;

	s1 = (unsigned char *) str;
	while (*s1)
	{
		if (*s1 < 32 || *s1 > 126)
		{
			write(1, "\\", 1);
			print(*s1 / 16);
			print(*s1 % 16);
		}
		else
		{	
			write(1, s1, 1);
		}
		s1 ++;
	}
}
