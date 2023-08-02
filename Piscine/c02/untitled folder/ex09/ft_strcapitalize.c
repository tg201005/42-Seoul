/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:20:27 by tyi               #+#    #+#             */
/*   Updated: 2022/05/28 17:42:51 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	alltolow(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] += 32;
		i ++;
	}
}

void	iflowtoup(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	alltolow(str);
	i = -1;
	while (str[++i])
	{
		if (i == 0)
			iflowtoup(str, i);
		else
		{
			if (('0' > str[i - 1] || 'z' < str[i - 1]))
				iflowtoup(str, i);
			else if ('9' < str[i - 1] && 'A' > str[i - 1])
				iflowtoup(str, i);
			else if ('Z' < str[i - 1] && 'a' > str[i - 1])
				iflowtoup(str, i);
		}
	}
	return (str);
}
