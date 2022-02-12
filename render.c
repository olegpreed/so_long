/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/02/11 20:23:33 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	symbol_to_image(t_root *game, t_vector xy, int i, int k)
{
	static int	j;

	if (game->map[i] == '1' || game->map[i] == 'D')
		walls(game, xy, i, k);
	else if (game->map[i] == '0' || game->map[i] == 'T')
		print_image(game, &(game->i.floor), xy, i);
	else if (game->map[i] == 'P')
		player(game, xy, i);
	else if (game->map[i] == 'C')
		collectible(game, xy, i, j);
	else if (game->map[i] == 'E' || game->map[i] == 'L')
		j = lady(game, xy, i);
}

void	status_changed(t_root *game)
{
	static int	k;
	static int	n;

	if (game->status == WIN || game->status == RECORD)
		hearts(game);
	if (game->status == RECORD)
		display_score(game);
	if (game->status == OVER)
		game_over(game);
	if (!ft_strchr(game->map, 'C'))
		*game->i.lady.pixels = 'L';
	if (game->p_status == DRUNK)
		k = 1;
	if (k)
		n++;
	if (n == 80)
	{
		game->p_status = SOBER;
		n = 0;
		k = 0;
	}
}

void	overlay(t_root *game)
{
	fence(game, &(game->i.fence));
	score(game);
	darken(game);
}

int	map(t_root *game)
{	
	t_vector	xy;
	int			i;

	xy.x = 0;
	xy.y = 0;
	i = -1;
	while ((game->map)[++i])
	{
		if ((game->map)[i] == '\n')
		{
			xy.x = 0;
			xy.y += game->i.floor.size.y;
		}
		else
		{
			symbol_to_image(game, xy, i, game->k);
			xy.x += game->i.floor.size.x;
		}
	}
	patrol(game);
	overlay(game);
	status_changed(game);
	animation_cykle(game);
	return (1);
}
