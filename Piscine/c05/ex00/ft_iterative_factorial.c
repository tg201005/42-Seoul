/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:53:36 by tyi               #+#    #+#             */
/*   Updated: 2022/05/31 10:32:18 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	res = 1;
	n = 1;
	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	else
	{	
		while (++ n < nb + 1)
			res *= n;
		return (res);
	}
}
