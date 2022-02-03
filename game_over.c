/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:02:44 by oleg              #+#    #+#             */
/*   Updated: 2022/02/03 15:34:19 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	slow_image(t_root *game, int x, int y)
{
	int	c;

	c = 0;
	while (c < 100)
	{
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.max_o.reference, x, y);
		c++;
	}
}

void	max_kicked_out(t_root *game)
{
	static int	x;
	static int	y;
	static int	c;
	static int	k;

	if (c < 100 && !k)
	{
		c++;
		return ;
	}
	if (!k)
	{
		game->i.max_o.symbol_index = 42;
		game->i.max_o.pixel_loc.y++;
		game->i.max_o.pixel_loc.x++;
		y = game->pixelsize.y - game->i.wall.size.y;
		x = game->pixelsize.x - 4 * game->i.wall.size.x + 10;
		k = 1;
		while (x > game->pixelsize.x - 4 * game->i.wall.size.x - 100)
		{
			while (y > game->pixelsize.y - game->i.wall.size.y - 30)
			{
				slow_image(game, x, y);
				y--;
				x--;
			}
			while (y < game->pixelsize.y - game->i.wall.size.y)
			{
				slow_image(game, x, y);
				y++;
				x--;
			}
		}
	}
}

void	game_over(t_root *game)
{
	fade_to_black(game);
	max_kicked_out(game);
	//exit_game();
}
