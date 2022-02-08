/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:02:44 by oleg              #+#    #+#             */
/*   Updated: 2022/02/07 21:50:22 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	slow_image(void)
// {
// 	int	c;

// 	c = 0;
// 	while (c < 10)
// 	{
// 		c++;
// 	}
// }

void	restart(t_root *game)
{
	static int	x;
	int	y;
	int h;
	int w;

	x = game->pixelsize.x / 2;
	y = game->pixelsize.y / 2;
	w = game->i.gameover.size.x;
	h = game->i.gameover.size.y;
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.gameover.reference, x - w / 2, y - h / 2);
	x += game->m.select.pixel_loc.x;
	mlx_put_image_to_window(game->mlx, game->mlxw, game->m.select.reference, x - 130, y + 46);
	game->restart = 1;
}

int	max_kicked_out(t_root *game)
{
	static int	x;
	static int	y;
	static int	c;
	static int	k;
	static int	s;

	if (c < 100 && !k)
	{
		c++;
		game->i.max_o.symbol_index = 0;
		return (0);
	}
	if (!k)
	{
		if (game->i.max_o.symbol_index == 0)
		{
			y = game->pixelsize.y - game->i.wall.size.y + 10;
			x = game->pixelsize.x - 4 * game->i.wall.size.x + 10;
		}
		game->i.max_o.symbol_index = 42;
		while (x > game->pixelsize.x - 4 * game->i.wall.size.x - 60)
		{
			if (!s)
			{
				while (y > game->pixelsize.y - game->i.wall.size.y - 10)
				{
					y--;
					x--;
					game->i.max_o.pixel_loc.x = x;
					game->i.max_o.pixel_loc.y = y;
					if (y <= game->pixelsize.y - game->i.wall.size.y - 10)
						s = 1;
					return (1);
				}
			}
			if (s == 1)
			{
				while (y < game->pixelsize.y - game->i.wall.size.y)
				{
					y += 2;
					x--;
					game->i.max_o.pixel_loc.x = x;
					game->i.max_o.pixel_loc.y = y;
					if (y >= game->pixelsize.y - game->i.wall.size.y)
						s = 0;
					return (1);
				}
			}
		}
	}
	restart(game);
	return (1);
}

void	game_over(t_root *game)
{
	static int	x;
	static int	y;
	
	x = game->i.max_o.pixel_loc.x;
	y = game->i.max_o.pixel_loc.y;
	fade_to_black(game);
	if (max_kicked_out(game))
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.max_o.reference, game->i.max_o.pixel_loc.x, game->i.max_o.pixel_loc.y);
	//exit_game();
}
