/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:40:48 by tyi               #+#    #+#             */
/*   Updated: 2022/06/09 12:12:36 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	checksep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i ++;
	}
	return (0);
}

char	*resput(char *str, int a, int b)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (b - a + 1));
	if (!res)
		return (0);
	while (a < b)
	{
		res[i] = str[a];
		a++;
		i++;
	}
	res[i] = 0;
	return (res);
}

int	lenword(char *charset, char *str)
{
	int	i;
	int	first;
	int	last;
	int	cnt;

	cnt = 0;
	i = -1;
	first = 0;
	last = 0;
	while (str[++i])
	{
		if (checksep(str[i], charset) == 1 && \
				checksep(str[i + 1], charset) == 0)
			first = i + 1;
		else if (checksep(str[i], charset) == 0 && ((checksep(str[i + 1], \
							charset) == 1) || (str[i + 1] == 0)))
			last = i + 1;
		if (first < last)
		{
			last = 0;
			cnt ++;
		}
	}
	return (cnt);
}

char	**makeres(char **res, char *charset, char *str, int size)
{
	int		i;
	int		first;
	int		last;

	i = -1;
	first = 0;
	last = 0;
	while (str[++i])
	{
		if (checksep(str[i], charset) == 1 && \
				checksep(str[i + 1], charset) == 0)
			first = i + 1;
		else if (checksep(str[i], charset) == 0 && ((checksep(str[i + 1], \
							charset) == 1) || (str[i + 1] == 0)))
			last = i + 1;
		if (first < last)
		{
			res[++size] = resput(str, first, last);
			last = 0;
		}
	}
	res[size + 1] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		cnt;

	cnt = 0;
	i = -1;
	while (str[++i])
	{
		if (checksep(str[i], charset) == 1)
			cnt ++;
	}
	res = (char **)malloc(sizeof(char *) * (lenword(charset, str) + 1));
	if (!res)
		return (0);
	return (makeres(res, charset, str, -1));
}
