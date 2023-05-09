// File: check_map.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"


typedef struct	s_info
{
	int	a;
}				t_info;


void check(t_info *info, char *av)
{
	int fd;
	char *line;
	int i;

	(void) info;
	i = 0;
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ; 
		printf("%s\n", line);
		free(line);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_info info;

	ac =1;

	check(&info, av[1]);

	return (0);
}