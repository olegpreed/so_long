/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:02:44 by oleg              #+#    #+#             */
/*   Updated: 2022/02/12 15:20:03 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart(t_root *game, int a)
{
	int	x;
	int	y;
	int	h;
	int	w;

	x = game->pixelsize.x / 2;
	y = game->pixelsize.y / 2;
	w = game->i.gameover.size.x;
	h = game->i.gameover.size.y;
	if (!a)
		mlx_img(game, game->i.gameover.ref, x - w / 2, y - h / 2 - 50);
	else
	{
		mlx_img(game, game->i.continue_s.ref, x - w / 2 + 60, y - h / 2 + 10);
		x += game->m.select.pixel_loc.x;
		mlx_img(game, game->m.select.ref, x - 125, y + 40);
	}
	game->status = CONTINUE;
}

int	max_kicked_out_cyckle(t_root *game, int *x, int *y, int *s)
{
	if (!*s)
	{
		while (*y > game->pixelsize.y - game->i.wall.size.y - 10)
		{
			(*y)--;
			(*x)--;
			game->i.max_o.pixel_loc.x = *x;
			game->i.max_o.pixel_loc.y = *y;
			if (*y <= game->pixelsize.y - game->i.wall.size.y - 10)
				*s = 1;
			return (1);
		}
	}
	while (*y < game->pixelsize.y - game->i.wall.size.y)
	{
		*y += 2;
		(*x)--;
		game->i.max_o.pixel_loc.x = *x;
		game->i.max_o.pixel_loc.y = *y;
		if (*y >= game->pixelsize.y - game->i.wall.size.y)
			*s = 0;
		return (1);
	}
	return (1);
}

int	max_kicked_out(t_root *game, int *c)
{
	static int	x;
	static int	y;
	static int	k;
	static int	s;

	if (*c < 100 && !k)
	{
		(*c)++;
		game->i.max_o.symbol_index = 0;
		return (0);
	}
	restart(game, 0);
	if (!k)
	{
		if (game->i.max_o.symbol_index == 0)
		{
			y = game->pixelsize.y - game->i.wall.size.y + 10;
			x = game->pixelsize.x - 4 * game->i.wall.size.x + 10;
		}
		game->i.max_o.symbol_index = 42;
		while (x > game->pixelsize.x - 4 * game->i.wall.size.x - 60)
			return (max_kicked_out_cyckle(game, &(x), &(y), &(s)));
	}
	restart(game, 1);
	return (1);
}

void	game_over(t_root *game)
{
	int			x;
	int			y;
	static int	c;

	if (game->restart)
		c = 0;
	fade_to_black(game);
	if (max_kicked_out(game, &c))
	{
		x = game->i.max_o.pixel_loc.x;
		y = game->i.max_o.pixel_loc.y;
		mlx_img(game, game->i.max_o.ref, x, y);
	}
}
