/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:43 by tyi               #+#    #+#             */
/*   Updated: 2023/05/10 20:46:56 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./parsing.h"

unsigned int rgb_to_hex(char *rgb)
{
	unsigned int hex;
	int r;
	int g;
	int b;

 	char **rgb_arr = ft_split(rgb, ',');
	r = atoi(rgb_arr[0]);
	g = atoi(rgb_arr[1]);
	b = atoi(rgb_arr[2]);

	if (r < 0 || r > 255)
	{
		printf("Error\n");
		exit(0);
	}
	if (g < 0 || g > 255)
	{
		printf("Error\n");
		exit(0);
	}
	if (b < 0 || b > 255)
	{
		printf("Error\n");
		exit(0);
	}
	hex = (r << 16) + (g << 8) + b;
	return (hex);
}


int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void check_file_open(char *path)
{
	int fd;
	int end;

	end = ft_strlen(path);
	path[end - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		//printf error fd av
		printf("Error \n");
		printf ("fd: %d\n", fd);
		exit(0);
	}
	close(fd);
}

void fill_info(char *line, t_info *info)
{
	char **key_value;

	key_value = ft_split(line, ' ');
	if (ft_strcmp(key_value[0], "NO") && key_value[1] != NULL)
	{
		info->N_texpath = key_value[1];
		check_file_open(info->N_texpath);
	}
	else if (ft_strcmp(key_value[0], "SO") && key_value[1] != NULL)
	{
		info->S_texpath = key_value[1];
		check_file_open(info->S_texpath);
	}
	else if (ft_strcmp(key_value[0], "WE") && key_value[1] != NULL)
	{
		info->W_texpath = key_value[1];
		check_file_open(info->W_texpath);
	}
	else if (ft_strcmp(key_value[0], "EA") && key_value[1] != NULL)
	{
		info->E_texpath = key_value[1];
		check_file_open(info->E_texpath);
	}
	else if (ft_strcmp(key_value[0], "F") && key_value[1] != NULL)
		info->floor_color = rgb_to_hex(key_value[1]);
	else if (ft_strcmp(key_value[0], "C") && key_value[1] != NULL)
		info->ceiling_color = rgb_to_hex(key_value[1]);
	else
	{
		printf("Error_in_fill\n");
		exit (0);
	}
	free (key_value);
	free (line);
}

int line_is_new_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

int line_is_in_map(t_info *info)
{
	if (info->N_texpath == 0)
		return (0);
	if (info->S_texpath == 0)
		return (0);
	if (info->W_texpath == 0)
		return (0);
	if (info->E_texpath == 0)
		return (0);
	if (info->floor_color == 0)
		return (0);
	if (info->ceiling_color == 0)
		return (0);
	return (1);
}

void print_info(t_info *info)
{
	printf("NO : %s\n", info->N_texpath);
	printf("SO : %s\n", info->S_texpath);
	printf("WE : %s\n", info->W_texpath);
	printf("EA : %s\n", info->E_texpath);
	printf("F : %d\n", info->floor_color);
	printf("C : %d\n", info->ceiling_color);
	printf("mapWidth : %d\n", info->mapWidth);
	printf("mapHeight : %d\n", info->mapHeight);
	printf("map : \n");
	for (int i = 0; i < info->mapHeight; i++)
	{
		printf("%s\n", info->map[i]);
	}
	printf("point_of_view : %c\n", info->player_view);
	printf ("------------------\n");
}


void fill_check_info(t_info *info, char *av)
{
	int fd;
	char *line;
	int i;

	i = 0;
	info->map = (char **)malloc(sizeof(char *) * 100);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit(0);
	}
	while (1)
	{
		line = get_next_line(fd);
		printf ("line = %s\n", line);
		// printf ("in_map %d\n",line_is_in_map(info));
		if (line == NULL)
			break ;
		else if (line_is_new_line(line))
		{
			free(line); 
			continue;
		}
		else if (!line_is_in_map(info))
		{
			fill_info(line, info);
			continue ;
		}
		else if (line_is_in_map(info))
		{
			info->map[i] = line;
			info->mapWidth= ft_strlen(line) - 1;
			//check length of line
			i++;
			continue ;
		}
		else
		{
			printf("Error\n");
			exit(0);
		}
		free(line);
	}
	info->mapHeight = i;
	close(fd);
	print_info(info);
	// check_map(info);
}

void	init_info(t_info *info)
{
	info->N_texpath = 0;
	info->S_texpath = 0;
	info->W_texpath = 0;
	info->E_texpath = 0;
	info->floor_color = 0;
	info->ceiling_color = 0;
	info->mapWidth = 0;
	info->mapHeight = 0;
	info->map = 0;
	info->player_view = 0;
}

int	main(int ac, char **av)
{
	t_info info;

	ac =1;
	init_info(&info);
	fill_check_info(&info, av[1]);
	return (0);
}

// int main ()
// {
// 	int fd;

// 	fd= open("./map.cub\n", O_RDONLY);
// 	printf ("fd = %d\n", fd);
// }