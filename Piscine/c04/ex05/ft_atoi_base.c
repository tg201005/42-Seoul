/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:11:30 by tyi               #+#    #+#             */
/*   Updated: 2022/05/31 12:41:42 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_res1(int *res, char *base, int flag)
{
	int	l;

	l = 0;
	while (base[l])
		l ++;
	*res = l * (*res) + flag;
}

int	ft_atoi1(char *str, char *base)
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
		ft_res1(&res, base, flag);
		i ++;
	}
	return (sign * res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	l;
	int	n;

	l = -1;
	n = 0;
	while (base[++l])
	{	
		if (base[l] == '-' || base[l] == '+' || \
		base[l] > 126 || base[l] < 33)
			return (0);
	}
	if (l < 2)
		return (0);
	if (check_same1(base, l))
		return (0);
	return (ft_atoi1(str, base));
}
