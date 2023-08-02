/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:33:59 by tyi               #+#    #+#             */
/*   Updated: 2022/06/01 16:21:20 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
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

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb)
	{	
		if (ft_is_prime1(nb))
			return (nb);
		nb ++;
	}
	return (0);
}
