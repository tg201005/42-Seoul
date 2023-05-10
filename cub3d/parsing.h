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
	int		floor_color;
	int		ceiling_color;	
	
	int		mapWidth;
	int		mapHeight;
	char	**map;

	char	player_view;
	int 	player_x;
	int		player_y;

}				t_info;

void check_map(t_info *info);