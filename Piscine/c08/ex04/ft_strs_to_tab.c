/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:23:08 by tyi               #+#    #+#             */
/*   Updated: 2022/06/05 14:28:56 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (len(s) + 1));
	while (s[i])
	{
		res[i] = s[i];
		i ++;
	}
	res[i] = '\0';
	return (res);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*p;

	p = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < ac)
	{
		p[i].size = len(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		i ++;
	}
	p[i].str = 0;
	return (p);
}
