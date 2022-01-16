#include "so_long.h"

int map(t_root *game)
{	
	int x = 0;
	int y = 0;
	int i = 0;
	while ((game->map)[i])
	{
			if ((game->map)[i] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->mlxw, game->wall.reference, x, y);
				x += game->grass.size.x;
			}
			else if ((game->map)[i] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->mlxw, game->grass.reference, x, y);
				x += game->grass.size.x;
			}
			else if ((game->map)[i] == '\n')
			{
				x = 0;
				y += game->grass.size.y;
			}
		i++;
	}
	return 1;
}