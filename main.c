#include "so_long.h"

int main()
{
	t_root game;

	map_to_string(&game);
	game.mlx = mlx_init();
	start(&game);
	game.mlxw = mlx_new_window(game.mlx, game.pixelsize.x, game.pixelsize.y, "Approach");
	mlx_key_hook(game.mlxw, &action, &game);
	mlx_loop_hook(game.mlx, &map, &game);
	mlx_loop(game.mlx);
}