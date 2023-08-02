/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:56:20 by tyi               #+#    #+#             */
/*   Updated: 2022/06/07 17:28:09 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_inbase(char c, char *base, int *flag);
int		len1(char *str);
int		check_same1(char *base, int l);
int		ft_atoi(char *str, char *base);
void	to_strl(long nbr, char *base, int l, char *strl);
int		lx(int n, int l);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		base_error(char *base);

void	to_strl(long nbr, char *base, int l, char *strl)
{
	if (nbr >= l)
		to_strl(nbr / l, base, l, strl - 1);
	*(strl) = base[nbr % l];
}

int	lx(int n, int l)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / l;
		i ++;
	}
	return (i);
}	

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*strl;
	int		i;

	if (base_error(base_from) || base_error(base_to))
		return (0);
	n = ft_atoi(nbr, base_from);
	i = lx(n, len1(base_to));
	strl = (char *)malloc(sizeof(char) * (i + 2));
	if (!strl)
		return (0);
	if (n < 0)
	{
		n = -1 * n;
		i ++;
		strl[0] = '-';
	}
	to_strl(n, base_to, len1(base_to), strl + i - 1);
	strl[i] = 0;
	return (strl);
}
