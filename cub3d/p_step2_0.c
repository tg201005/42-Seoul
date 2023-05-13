/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_step2_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:56:54 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 14:45:11 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	push_before_map(int map_start_idx, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map_start_idx)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
}

char	*strdup_len(int width, char *line)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (width + 1));
	if (!ret)
		exit_with_error("malloc error");
	while (line[i + 1])
	{
		ret[i] = line[i];
		i++;
	}
	while (i < width)
		ret[i++] = ' ';
	ret[i] = '\0';
	free(line);
	return (ret);
}

void	fill_map(t_info *info, int fd)
{
	int		i;
	char	*line;

	i = 0;
	info->map = (char **)malloc(sizeof(char *) * (info->mapHeight + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_is_new_line(line))
			free(line);
		else
			info->map[i++] = strdup_len(info->mapWidth, line);
	}
	info->map[info->mapHeight] = NULL;
	close(fd);
}

void	step2(t_info *info, int fd)
{
	push_before_map(info->map_start_idx, fd);
	fill_map(info, fd);
	close(fd);
}
