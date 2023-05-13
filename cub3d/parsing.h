/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:10:47 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:12:03 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"

// #define width 640
// #define height 480

typedef struct s_info
{
	char	*N_texpath;
	char	*S_texpath;
	char	*W_texpath;
	char	*E_texpath;

	int		texWidth;
	int		texHeight;

	int		floor_color;
	int		ceiling_color;	

	int		map_start_idx;
	int		mapWidth;
	int		mapHeight;
	char	**map;

	char	player_view;
	int		player_x;
	int		player_y;
}				t_info;

void	check_map_valid(t_info *info);
void	step1(t_info *info, int fd);
void	step2(t_info *info, int fd);
void	exit_with_error(char *msg);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		line_is_new_line(char *line);
int		line_is_in_map(t_info *info);
void	print_info(t_info *info);
void	check_file_open(char **path, char *value);
int		cub_file_open(char *path);
int		ft_double_arr_len(char **arr);
void	free_double_arr(char **arr);

#endif