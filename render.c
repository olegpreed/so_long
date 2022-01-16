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
			else if ((game->map)[i] == '0' || (game->map)[i] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->mlxw, game->grass.reference, x, y);
				x += game->grass.size.x;
			}
			else if ((game->map)[i] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlxw, game->grass.reference, x, y);
				mlx_put_image_to_window(game->mlx, game->mlxw, game->ball.reference, x + 25, y + 25);
				x += game->grass.size.x;
			}
			else if ((game->map)[i] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlxw, game->grass.reference, x, y);
				mlx_put_image_to_window(game->mlx, game->mlxw, game->pika.reference, x, y);
				x += game->grass.size.x;
			}
			else if ((game->map)[i] == '\n')
			{
				x = 0;
				y += game->grass.size.y;
			}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlxw, game->ash.reference, game->ash.pixel_location.x, game->ash.pixel_location.y);
	return 1;
}