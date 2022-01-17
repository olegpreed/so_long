#include "so_long.h"

int main()
{
	t_root game;

	map_to_string(&game);
	if (check_valid_map(&game))
	{
		printf("Error\nInvalid map\n");
		return 1;
	}
	game.mlx = mlx_init();
	start(&game);
	game.mlxw = mlx_new_window(game.mlx, game.pixelsize.x, game.pixelsize.y, "Approach");
	mlx_hook(game.mlxw, 2, 0, &action, &game);
	mlx_loop_hook(game.mlx, &map, &game);
	mlx_loop(game.mlx);
	return 0;
}