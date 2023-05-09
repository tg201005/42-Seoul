// File: check_map.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"


#define width 640
#define height 480


typedef struct	s_info
{
	char	*N_texpath;
	char	*S_texpath;
	char	*W_texpath;
	char	*E_texpath;

	int	texWidth;
	int	texHeight;

	//hexadecimal color	
	unsigned int		floor_color;
	unsigned int		ceiling_color;
	
	
	int		mapWidth;
	int		mapHeight;
	char	**map;

	int		point_of_view;


}				t_info;

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

void check_file_open(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit(0);
	}
	close(fd);
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
	{
		info->floor_color = rgb_to_hex(key_value[1]);
	}
	else if (ft_strcmp(key_value[0], "C") && key_value[1] != NULL)
	{
		info->ceiling_color = rgb_to_hex(key_value[1]);
	}
	else
		exit (0);
	free (key_value);
	free (line);
}

void	check_linking_zereos(t_info *info, int i, int j)
{
	char **map = info->map;

	if (i != 0)
	{
		if (map[i - 1][j] == '0')
		{
			printf("Error\n");
			exit(0);
		}
	}
	if (i != info->mapHeight - 1)
	{
		if (map[i + 1][j] == '0')
		{
			printf("Error\n");
			exit(0);
		}
	}
	if (j != 0)
	{
		if (map[i][j - 1] == '0')
		{
			printf("Error\n");
			exit(0);
		}
	}
	if (j != info->mapWidth - 1)
	{
		if (map[i][j + 1] == '0')
		{
			printf("Error\n");
			exit(0);
		}
	}
}

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
void check_map(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j] != '\n')
		{
			printf( "i = %d, j = %d\n", i, j);

			//printf mapheight
			//printf mapwidth
			if (is_space(info->map[i][j]))
			{
				check_linking_zereos(info, i, j);
			}
			else if (is_num(info->map[i][j]))
			{
				if (info->map[i][j] == '0')
				{
					if (i == 0 || i == info->mapHeight - 1 || j == 0 || j == info->mapWidth)
					{
						printf("Error\n");
						exit(0);
					}
				}
			}
			else if (is_nswe(info->map[i][j]))
			{
				info->point_of_view = info->map[i][j];
			}
			else
			{
						printf("%d %d\n", i, j);
				printf("Err1or\n");
				exit(0);
			}
			j++;
		}
		// printf("%s\n", info->map[i]);
		i++;
	}
	printf ("map is ok\n");
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

int	ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (line == NULL)
			break ;
		// if (line_is_new_line(line))
		// {
		// 	free(line);
		// 	continue ;
		// }
		// if (!line_is_in_map(line, info))
		if (!line_is_in_map(info))
		{
			info->map[i] = line;
			info->mapWidth= ft_len(line) - 1;
			//check length of line
			i++;
			// printf ("%s\n", line);
			continue ;
		}
		free(line);
	}
	info->mapHeight = i;
	close(fd);
	check_map(info);
}

// void print_info(t_info *info)
// {
// 	printf("R : %d %d\n", info->R_width, info->R_height);
// 	printf("NO : %s\n", info->N_texpath);
// 	printf("SO : %s\n", info->S_texpath);
// 	printf("WE : %s\n", info->W_texpath);
// 	printf("EA : %s\n", info->E_texpath);
// 	printf("F : %d\n", info->floor_color);
// 	printf("C : %d\n", info->ceiling_color);
// 	printf("mapWidth : %d\n", info->mapWidth);
// 	printf("mapHeight : %d\n", info->mapHeight);
// 	printf("map : \n");
// 	for (int i = 0; i < info->mapHeight; i++)
// 	{
// 		printf("%s\n", info->map[i]);
// 	}
// 	printf("point_of_view : %c\n", info->point_of_view);
// }

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
	info->point_of_view = 0;
}


int	main(int ac, char **av)
{
	t_info info;

	ac =1;
	init_info(&info);
	fill_check_info(&info, av[1]);
	// print_info(&info);
	return (0);
}