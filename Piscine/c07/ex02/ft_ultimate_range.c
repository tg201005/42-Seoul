/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:56:25 by tyi               #+#    #+#             */
/*   Updated: 2022/06/07 17:24:26 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	minu;

	minu = min;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
	{
		*(*range + i) = min;
		i ++;
		min ++;
	}
	return (max - minu);
}
