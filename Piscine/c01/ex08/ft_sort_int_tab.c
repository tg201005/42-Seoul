/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:59:58 by tyi               #+#    #+#             */
/*   Updated: 2022/05/28 20:17:52 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	n;
	int	m;
	int	emt;

	n = 0;
	m = 0;
	while (n < size - 1)
	{
		while (m < size - 1)
		{
			if (tab[m] > tab[m + 1])
			{
				emt = tab[m];
				tab[m] = tab[m + 1];
				tab[m + 1] = emt;
				m ++;
			}
			else 
				m ++;
		}
		m = 0;
		n ++;
	}
}


int main()
{
	int tarr8[10] = { 3, 7, 1, 0, 5, 9, 8, 2, 4, 6 };
    ft_sort_int_tab(tarr8, 10);
    for (int i = 0; i < 10; i++) 
	{
        printf("%d ", tarr8[i]);
    }
    printf("\n0 1 2 3 4 5 6 7 8 9 \n\n");
}
