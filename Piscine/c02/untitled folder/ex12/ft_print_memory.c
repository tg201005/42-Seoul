/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:23:24 by tyi               #+#    #+#             */
/*   Updated: 2022/06/04 16:35:43 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(long long str, int i)
{
	int			j;
	long long	m;

	j = -1;
	if (i > 0)
	{	
		if (str >= 16)
			print_memory(str / 16, i + 1);
		else
		{
			while (++j < 16 - i)
				write(1, "0", 1);
		}
	}
	m = "0123456789abcdef"[str % 16];
	write(1, &m, 1);
}

void	print_16(unsigned char *str, unsigned int j)
{	
	int	q;
	int	m;
	int	n;

	q = -1;
	while (str[16 * j + ++q] && q < 16)
	{
		m = "0123456789abcdef"[str[16 * j + q] / 16];
		n = "0123456789abcdef"[str[16 * j + q] % 16];
		write(1, &m, 1);
		write(1, &n, 1);
		if (q % 2 == 1)
			write(1, " ", 1);
	}
	if (q == 16)
		return ;
	write(1, "00", 2);
	while (++q < 16)
	{
		if (q % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
	write(1, " ", 1);
}

void	print_str(unsigned char *str, unsigned int j)
{
	int	i;

	i = 0;
	while (i < 16 && str[16 * j + i])
	{
		if (str[16 * j + i] < 32 || str[16 * j + i] > 126)
			write(1, ".", 1);
		else
			write(1, str + (16 * j) + i, 1);
		i ++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned char		*str;

	str = (unsigned char *) addr;
	i = (size / 16);
	if ((size % 16) != 0)
		i ++;
	j = 0;
	while (j < i)
	{
		print_memory((long long)str + (16 * j), 1);
		write(1, ": ", 2);
		print_16(str, j);
		print_str(str, j);
		write(1, "\n", 1);
		j ++;
	}
	return (addr);
}
