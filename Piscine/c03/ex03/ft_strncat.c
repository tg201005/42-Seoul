/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:37:57 by tyi               #+#    #+#             */
/*   Updated: 2022/05/30 11:02:58 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len3(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		i ++;
		str ++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	m;

	n = len3(dest);
	m = len3(src);
	i = 0;
	while ((i < m) && (i < nb))
	{
		dest[n + i] = src[i];
		i ++;
	}
	dest[n + i] = '\0';
	return (dest);
}
