/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:14:12 by tyi               #+#    #+#             */
/*   Updated: 2022/06/01 15:25:02 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb < 4)
		return (1);
	else
	{
		while (i * i <= nb)
		{
			if (nb % i == 0)
				return (0);
			i ++;
		}
	}
	return (1);
}
