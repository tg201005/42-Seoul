typedef struct	s_data
{
	char	*N_texpath;
	char	*S_texpath;
	char	*W_texpath;
	char	*E_texpath;
	unsigned int		floor_color;
	unsigned int		ceiling_color;
	int		mapWidth;
	int		mapHeight;
	char	**map;



	void	*win;
}				t_data;

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 500, 500, "mlx 42");
		mlx_loop(data.mlx);
	}
	else
		ft_putstr("Error\n");
	return (0);
}