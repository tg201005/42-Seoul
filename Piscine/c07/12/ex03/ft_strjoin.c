/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:06:03 by tyi               #+#    #+#             */
/*   Updated: 2022/06/08 21:39:37 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	strcat1(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i ++;
	while (s2[j])
	{
		s1[i] = s2[j];
		j ++;
		i ++;
	}
	s1[i] = '\0';
}

int	len(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i ++;
	return (i);
}

int	total_len(char **strs, char *sep, int size)
{
	int	tl;
	int	i;
	int	j;

	i = 0;
	tl = 0;
	while (i < size)
	{
		j = -1;
		while (strs[i][++j])
			tl ++;
		i ++;
	}
	tl += len(sep) * (size - 1) + 1;
	return (tl);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	i = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	res = (char *)malloc(sizeof(char) * total_len(strs, sep, size));
	if (!res)
		return (0);
	res[0] = 0;
	while (size)
	{
		strcat1(res, strs[i]);
		if (size != 1)
			strcat1(res, sep);
		size --;
		i ++;
	}
	return (res);
}
