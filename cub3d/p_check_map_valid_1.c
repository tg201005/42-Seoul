/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_map_valid_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:29:12 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 13:59:07 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '1')
		return (1);
	return (0);
}

int	is_nswe(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	check_linking_zereos(t_info *info, int i, int j)
{
	char	**map;

	map = info->map;
	if (i != 0)
	{
		if (map[i - 1][j] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (i != info->mapHeight - 1)
	{
		if (map[i + 1][j] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (j != 0)
	{
		if (map[i][j - 1] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (j != info->mapWidth - 1)
	{
		if (map[i][j + 1] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
}

void	check_zero_on_side(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0')
	{
		if (i == 0 || i == info->mapHeight - 1 || \
		j == 0 || j == info->mapWidth - 1)
			exit_with_error("Zero is on side Error\n");
	}
}
