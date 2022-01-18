/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 14:35:12 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_root *game, char key, int *count)
{
	if (key == 'w')
	{
		game->ash.symbol_loc.y -= 1;
		game->ash.pixel_loc.y -= game->grass.size.y;
	}
	else if (key == 'a')
	{
		game->ash.pixel_loc.x -= game->grass.size.x;
		game->ash.symbol_loc.x -= 1;
	}
	else if (key == 's')
	{
		game->ash.symbol_loc.y += 1;
		game->ash.pixel_loc.y += game->grass.size.y;
	}
	else if (key == 'd')
	{
		game->ash.pixel_loc.x += game->grass.size.x;
		game->ash.symbol_loc.x += 1;
	}
	(*count)++;
	printf("Move count!: %d\n", *count);
}

int	action(int keypress, t_root *game)
{
	static int	xx;
	static int	yy;
	static int	count;
	int			line;

	xx = game->ash.symbol_loc.x;
	yy = game->ash.symbol_loc.y;
	line = game->symbolsize.x;
	if (keypress == ESC)
	{
		mlx_destroy_window(game->mlx, game->mlxw);
		game->close = 1;
		return (1);
	}
	else if (keypress == W && game->map[xx + (line + 1) * (yy - 1)] != '1')
		move(game, 'w', &count);
	else if (keypress == A && game->map[(xx - 1) + (line + 1) * yy] != '1')
		move(game, 'a', &count);
	else if (keypress == S && game->map[xx + (line + 1) * (yy + 1)] != '1')
		move(game, 's', &count);
	else if (keypress == D && game->map[(xx + 1) + (line + 1) * yy] != '1')
		move(game, 'd', &count);
	return (0);
}
