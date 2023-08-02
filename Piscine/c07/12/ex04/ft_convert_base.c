/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:31:16 by tyi               #+#    #+#             */
/*   Updated: 2022/06/06 18:35:16 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_inbase(char c, char *base, int *flag);
int		len1(char *str);
int		check_same1(char *base, int l);
int		ft_atoi(char *str, char *base);
void	to_strl(long nbr, char *base, int l, char *strl);
int		lx(int n, int l);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		base_error(char *base);

int	len1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	check_same1(char *base, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < l - 1)
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

int	check_inbase(char c, char *base, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*flag = i;
			return (1);
		}
		i ++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base)
{
	int	res;
	int	sign;
	int	i;
	int	flag;

	flag = 0;
	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str [i] == 32)
		i ++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	while (check_inbase(str[i], base, &flag))
	{	
		res = len1(base) * (res) + flag;
		i ++;
	}
	return (sign * res);
}

int	base_error(char *base)
{
	int	l;
	int	n;

	l = -1;
	n = 0;
	while (base[++l])
	{
		if (base[l] == '-' || base[l] == '+' || \
				(base[l] >= 9 && base[l] <= 13) || base[l] == 32)
			return (1);
	}
	if (l < 2)
		return (1);
	if (check_same1(base, l))
		return (1);
	return (0);
}
