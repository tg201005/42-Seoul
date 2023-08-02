/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:36:25 by tyi               #+#    #+#             */
/*   Updated: 2022/06/06 19:36:26 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*p;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (src[n])
		n++;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (0);
	while (src[i])
	{
		p[i] = src[i];
		i ++;
	}
	p[i] = 0;
	return (p);
}
