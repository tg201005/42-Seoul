/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:10:31 by tyi               #+#    #+#             */
/*   Updated: 2023/05/10 20:45:57 by tyi              ###   ########.fr       */
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
	if (c >= '0' && c <= '2')
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
	char **map = info->map;

	if (i != 0)
	{
		if (map[i - 1][j] == '0')
			(printf("Error\n"), exit(0));
	}
	if (i != info->mapHeight - 1)
	{
		if (map[i + 1][j] == '0')
			(printf("Error\n"), exit(0));
	}
	if (j != 0)
	{
		if (map[i][j - 1] == '0')
			(printf("Error\n"), exit(0));
	}
	if (j != info->mapWidth - 1)
	{
		if (map[i][j + 1] == '0')
			(printf("Error\n"), exit(0));
	}
}

void	check_zero_on_side(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0')
	{
		if (i == 0 || i == info->mapHeight - 1 || j == 0 || j == info->mapWidth)
		{
			(printf("Error\n"), exit(0));
		}
	}
}

void check_map(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j] != '\n' && info->map[i][j] != '\0')
		{
			// printf( "i = %d, j = %d, elem = %c\n", i, j, info->map[i][j]);
			if (is_space(info->map[i][j]))
				check_linking_zereos(info, i, j);
			else if (is_num(info->map[i][j]))
				check_zero_on_side(info, i, j);
			else if (is_nswe(info->map[i][j]))
			{
				info->player_view = info->map[i][j];
				info->player_x = j;
				info->player_y = i;
			}
			else
			{
				printf("Error\n");
				exit(0);
			}
			j++;
		}
		// printf("%s\n", info->map[i]);
		i++;
	}
	// printf ("map is ok\n");
}
