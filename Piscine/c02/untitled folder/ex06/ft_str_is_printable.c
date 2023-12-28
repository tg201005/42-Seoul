/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:06:18 by tyi               #+#    #+#             */
/*   Updated: 2022/05/29 19:07:59 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{	
	int	i;

	i = -1;
	if (!str[0])
		return (1);
	while (str[++i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
	}
	return (1);
}