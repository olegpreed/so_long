#include <mlx.h>
#include <stdio.h>

typedef struct s_root
{
	void	*mlx;
	void	*mlxw;
	void	*mlx2;
	void	*mlxw2;
	void	*img;
	void	*add;
	int 	w;
	int		h;
	int		k;
}			t_root;

int	render2(t_root *game)
{
	mlx_put_image_to_window(game->mlx, game->mlxw2, game->img, 30, 40);
	//mlx_loop(game->mlx2);
	return 0;

}

int	render(t_root *game)
{
	if (!game->k)
		mlx_put_image_to_window(game->mlx, game->mlxw, game->img, 0, 0);
	return 0;
}

int press(int keypress, t_root *game)
{
	if (keypress == 36)
	{
		game->k = 1;
		game->mlxw2 = mlx_new_window(game->mlx, 500, 500, "New");
		mlx_destroy_window(game->mlx, game->mlxw);
		mlx_loop_hook(game->mlx, render2, game);
		
	}
	return 0;
}

int	main()
{
	t_root game;

	game.k = 0;
	game.mlx = mlx_init();
	//game.mlx2 = mlx_init();
	game.img = mlx_xpm_file_to_image(game.mlx, "../images/max.xpm", &(game.w), &(game.h));
	game.mlxw = mlx_new_window(game.mlx, 300, 300, "Menu");
	mlx_hook(game.mlxw, 2, 0, press, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	
	
}