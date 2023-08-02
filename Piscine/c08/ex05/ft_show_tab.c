/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:33:39 by tyi               #+#    #+#             */
/*   Updated: 2022/06/06 20:11:44 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_nbr(long n)
{
	if (n >= 10)
		put_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	put_str(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i ++;
	write(1, s1, i);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		put_str(par[i].str);
		write(1, "\n", 1);
		put_nbr(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		write(1, "\n", 1);
		i ++;
	}
}
