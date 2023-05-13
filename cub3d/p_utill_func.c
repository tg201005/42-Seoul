/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utill_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:46 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:12:03 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	check_file_open(char **path, char *value)
{
	int	fd;
	int	end;

	*path = value;
	end = ft_strlen(*path);
	path[0][end - 1] = '\0';
	fd = open(*path, O_RDONLY);
	if (fd == -1)
		exit_with_error("tex File open Error\n");
	close(fd);
}

int	cub_file_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("cub File open Error\n");
	return (fd);
}

int	line_is_new_line(char *line)
{
	if (line == NULL)
		return (0);
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	line_is_in_map(t_info *info)
{
	if (info->N_texpath == 0)
		return (0);
	if (info->S_texpath == 0)
		return (0);
	if (info->W_texpath == 0)
		return (0);
	if (info->E_texpath == 0)
		return (0);
	if (info->floor_color == -1)
		return (0);
	if (info->ceiling_color == -1)
		return (0);
	return (1);
}

void	print_info(t_info *info)
{
	int	i;

	i = -1;
	printf("NO : %s\n", info->N_texpath);
	printf("SO : %s\n", info->S_texpath);
	printf("WE : %s\n", info->W_texpath);
	printf("EA : %s\n", info->E_texpath);
	printf("F : %d\n", info->floor_color);
	printf("C : %d\n", info->ceiling_color);
	printf("map_start_idx : %d\n", info->map_start_idx);
	printf("mapWidth : %d\n", info->mapWidth);
	printf("mapHeight : %d\n", info->mapHeight);
	if (info->map != NULL)
	{
		printf("map : \n");
		while (info->map[++i])
			printf("%s\n", info->map[i]);
	}
	printf("point_of_view : %c\n", info->player_view);
	printf("player_x : %d\n", info->player_x);
	printf("player_y : %d\n", info->player_y);
	printf ("------------------\n");
}
