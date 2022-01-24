/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/01/21 19:15:02 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_sd(t_root *game, char key, int *count, int j)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 's')
	{
		game->map[j + game->symbolsize.x + 1] = 'P';
		game->map[j] = '0';
		game->i.max.symbol_loc.y += 1;
		game->i.max.pixel_loc.y += game->i.floor.size.y;
		game->i.max.reference = image_ref(game, &(game->i.max));
	}
	else if (key == 'd')
	{
		game->map[j + 1] = 'P';
		game->map[j] = '0';
		game->i.max.pixel_loc.x += game->i.floor.size.x;
		game->i.max.symbol_loc.x += 1;
		game->i.max.reference = image_ref(game, &(game->i.max_r));
	}
	*i = symbol_loc(game, line);
	(*count)++;
	printf("Move count: %d\n", *count);
}

void	move_wa(t_root *game, char key, int *count, int j)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 'w')
	{
		game->map[j - game->symbolsize.x - 1] = 'P';
		game->map[j] = '0';
		game->i.max.symbol_loc.y -= 1;
		game->i.max.pixel_loc.y -= game->i.floor.size.y;
		game->i.max.reference = image_ref(game, &(game->i.max_b));
	}
	else if (key == 'a')
	{
		game->map[j - 1] = 'P';
		game->map[j] = '0';
		game->i.max.pixel_loc.x -= game->i.floor.size.x;
		game->i.max.symbol_loc.x -= 1;
		game->i.max.reference = image_ref(game, &(game->i.max_l));
	}
	*i = symbol_loc(game, line);
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
	int i;

	xx = game->i.max.symbol_loc.x;
	yy = game->i.max.symbol_loc.y;
	line = game->symbolsize.x;
	i = ft_strchr(game->map, 'P') - game->map;
	if (keypress == ESC)
	{
		mlx_destroy_window(game->mlx, game->mlxw);
		exit(0);
	}
	else if (keypress == W && game->map[xx + (line + 1) * (yy - 1)] != '1')
		move_wa(game, 'w', &count, i);
	else if (keypress == A && game->map[(xx - 1) + (line + 1) * yy] != '1')
		move_wa(game, 'a', &count, i);
	else if (keypress == S && game->map[xx + (line + 1) * (yy + 1)] != '1')
		move_sd(game, 's', &count, i);
	else if (keypress == D && game->map[(xx + 1) + (line + 1) * yy] != '1')
		move_sd(game, 'd', &count, i);
	return (0);
}
