/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:43 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:15:00 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	init_info(t_info *info)
{
	info->N_texpath = 0;
	info->S_texpath = 0;
	info->W_texpath = 0;
	info->E_texpath = 0;
	info->floor_color = -1;
	info->ceiling_color = -1;
	info->mapWidth = 0;
	info->mapHeight = 0;
	info->map_start_idx = -1;
	info->map = 0;
	info->player_view = 0;
	info->player_x = 0;
	info->player_y = 0;
}

void	parsing(t_info *info, char *path)
{
	init_info(info);
	step1(info, cub_file_open(path));
	step2(info, cub_file_open(path));
	check_map_valid(info);
}

// int	main(int argc, char **argv)
// {
// 	t_info	info;

// 	if (argc == 2)
// 		parsing(&info, argv[1]);
// 	else
// 		exit_with_error("ARGV Error\n");
// 	print_info(&info);
// 	system("leaks cub3d");
// 	return (0);
// }
