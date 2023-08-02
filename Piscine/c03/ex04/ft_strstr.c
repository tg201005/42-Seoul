/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:12:38 by tyi               #+#    #+#             */
/*   Updated: 2022/05/29 20:13:45 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len4(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i ++;
		str ++;
	}
	return (i);
}

int	check_same(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 != *s2)
			return (0);
		s2 ++;
		s1 ++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	m;

	n = len4(str);
	m = len4(to_find);
	if (m == 0)
		return (str);
	while (*str)
	{	
		if (*str == to_find[0])
		{
			if (check_same(str, to_find) == 1)
				return (str);
		}
		str ++;
	}
	return (0);
}
