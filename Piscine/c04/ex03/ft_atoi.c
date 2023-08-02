/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:30:02 by tyi               #+#    #+#             */
/*   Updated: 2022/05/30 12:50:40 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_res(char c, int *res)
{
	*res = 10 * (*res) + c - '0';
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_res(str[i], &res);
		i ++;
	}
	return (sign * res);
}
