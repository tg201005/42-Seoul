/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_step1_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:26:59 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:12:03 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

int		is_space(char c);
int		is_num(char c);
int		is_nswe(char c);

int	ft_double_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

unsigned int	rgb_to_hex(char *rgb)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_arr;

	rgb_arr = ft_split(rgb, ',');
	if (ft_double_arr_len(rgb_arr) != 3)
		exit_with_error("num of RGB value is not valid Error\n");
	if (ft_strlen(rgb_arr[0]) > 3 || ft_strlen(rgb_arr[1]) > 3
		|| ft_strlen(rgb_arr[2]) > 4)
		exit_with_error("RGB value is not valid Error\n");
	r = ft_atoi(rgb_arr[0]);
	g = ft_atoi(rgb_arr[1]);
	b = ft_atoi(rgb_arr[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_with_error("RGB value is not valid Error\n");
	free_double_arr(rgb_arr);
	return ((r << 16) + (g << 8) + b);
}

void	fill_info(char *line, t_info *info)
{
	char	**key_value;

	key_value = ft_split(line, ' ');
	if (ft_double_arr_len(key_value) != 2)
		exit_with_error("Invalid num of key or value Error\n");
	if (ft_strcmp(key_value[0], "NO") && key_value[1] != NULL)
		check_file_open(&info->N_texpath, key_value[1]);
	else if (ft_strcmp(key_value[0], "SO") && key_value[1] != NULL)
		check_file_open(&info->S_texpath, key_value[1]);
	else if (ft_strcmp(key_value[0], "WE") && key_value[1] != NULL)
		check_file_open(&info->W_texpath, key_value[1]);
	else if (ft_strcmp(key_value[0], "EA") && key_value[1] != NULL)
		check_file_open(&info->E_texpath, key_value[1]);
	else if (ft_strcmp(key_value[0], "F") && key_value[1] != NULL)
		info->floor_color = rgb_to_hex(key_value[1]);
	else if (ft_strcmp(key_value[0], "C") && key_value[1] != NULL)
		info->ceiling_color = rgb_to_hex(key_value[1]);
	else
		exit_with_error("Invalid key or value Error\n");
	free_double_arr(key_value);
}

int	line_is_end_of_map(t_info *info, char *line)
{
	int	i;

	(void) info;
	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == ' '))
			return (0);
		i++;
	}	
	return (1);
}

int	line_is_middle_of_map(t_info *info, char *line)
{
	int	i;

	i = 0;
	if (info->mapWidth < ft_strlen(line) - 1)
		info->mapWidth = ft_strlen(line) - 1;
	while (line[i])
	{
		if (!(is_space(line[i]) || is_num(line[i]) || \
		is_nswe(line[i]) || line[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}
