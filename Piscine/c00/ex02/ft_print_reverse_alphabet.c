/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_print_reverse_alphabet.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:50:04 by tyi               #+#    #+#             */
/*   Updated: 2022/05/23 19:05:17 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	a;

	a = 122;
	while (a > 96)
	{
		write(1, &a, 1);
		a --;
	}
}
