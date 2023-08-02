/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:52:09 by tyi               #+#    #+#             */
/*   Updated: 2022/06/04 11:07:25 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	length(char *src)
{
	unsigned int	i;

	i = 0;
	while (*src)
	{
		src ++;
		i ++;
	}	
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{	
	unsigned int	i;
	unsigned int	l;

	l = length(src);
	i = 0;
	while (*src && (i + 1) < size)
	{
		*dest = *src;
		dest ++;
		src ++;
		i++;
	}
	*dest = '\0';
	return (l);
}
