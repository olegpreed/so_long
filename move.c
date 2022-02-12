/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:52:33 by oleg              #+#    #+#             */
/*   Updated: 2022/02/11 19:16:30 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drink(int j, int i, t_root *game)
{
	game->map[j] = '0';
	if (game->map[i] == 'C')
		game->p_status = DRUNK;
	return (0);
}

void	move_sd(t_root *game, char key, int j)
{
	int			*i;
	int			line;

	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 's')
	{
		drink(j, j + game->symbolsize.x + 1, game);
		game->map[j + game->symbolsize.x + 1] = 'P';
		game->i.max.symbol_loc.y += 1;
		game->i.max.pixel_loc.y += game->i.floor.size.y;
		game->i.max.symbol_index += (game->symbolsize.x + 1);
	}
	else if (key == 'd')
	{
		drink(j, j + 1, game);
		game->map[j + 1] = 'P';
		game->i.max.pixel_loc.x += game->i.floor.size.x;
		game->i.max.symbol_loc.x += 1;
		game->i.max.symbol_index += 1;
	}
	*i = symbol_loc(game, line);
	if (game->score != 9999)
		game->score++;
}

void	move_wa(t_root *game, char key, int j)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 'w')
	{
		drink(j, j - game->symbolsize.x - 1, game);
		game->map[j - game->symbolsize.x - 1] = 'P';
		game->i.max.symbol_loc.y -= 1;
		game->i.max.pixel_loc.y -= game->i.floor.size.y;
		game->i.max.symbol_index -= (game->symbolsize.x + 1);
	}
	else if (key == 'a')
	{
		drink(j, j - 1, game);
		game->map[j - 1] = 'P';
		game->i.max.pixel_loc.x -= game->i.floor.size.x;
		game->i.max.symbol_loc.x -= 1;
		game->i.max.symbol_index -= 1;
	}
	*i = symbol_loc(game, line);
	if (game->score != 9999)
		game->score++;
}
