/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 20:08:50 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_sd(t_root *game, char key, int *count)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->max.symbol_index);
	if (key == 's')
	{
		game->max.symbol_loc.y += 1;
		game->max.pixel_loc.y += game->floor.size.y;
	}
	else if (key == 'd')
	{
		game->max.pixel_loc.x += game->floor.size.x;
		game->max.symbol_loc.x += 1;
	}
	*i = pxl_to_symbol_loc(game, line);
	(*count)++;
	printf("Move count: %d\n", *count);
}

void	move_wa(t_root *game, char key, int *count)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->max.symbol_index);
	if (key == 'w')
	{
		game->max.symbol_loc.y -= 1;
		game->max.pixel_loc.y -= game->floor.size.y;
	}
	else if (key == 'a')
	{
		game->max.pixel_loc.x -= game->floor.size.x;
		game->max.symbol_loc.x -= 1;
	}
	*i = pxl_to_symbol_loc(game, line);
	(*count)++;
	printf("Move count: %d\n", *count);
}

int	exit_game(void)
{
	exit(0);
	return (1);
}

int	action(int keypress, t_root *game)
{
	static int	xx;
	static int	yy;
	static int	count;
	int			line;

	xx = game->max.symbol_loc.x;
	yy = game->max.symbol_loc.y;
	line = game->symbolsize.x;
	if (keypress == ESC)
	{
		mlx_destroy_window(game->mlx, game->mlxw);
		exit(0);
	}
	else if (keypress == W && game->map[xx + (line + 1) * (yy - 1)] != '1')
		move_wa(game, 'w', &count);
	else if (keypress == A && game->map[(xx - 1) + (line + 1) * yy] != '1')
		move_wa(game, 'a', &count);
	else if (keypress == S && game->map[xx + (line + 1) * (yy + 1)] != '1')
		move_sd(game, 's', &count);
	else if (keypress == D && game->map[(xx + 1) + (line + 1) * yy] != '1')
		move_sd(game, 'd', &count);
	return (0);
}
