/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:13:14 by oleg              #+#    #+#             */
/*   Updated: 2022/02/10 18:05:45 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	index_to_loc(int i, int j, t_root *game)
{
	int	w;
	int	h;

	w = game->i.floor.size.x;
	h = game->i.floor.size.y;
	game->thug[j].symbol_loc.x = i % (game->symbolsize.x + 1);
	game->thug[j].symbol_loc.y = i / (game->symbolsize.x + 1);
	game->thug[j].pixel_loc.x = game->thug[j].symbol_loc.x * w;
	game->thug[j].pixel_loc.y = game->thug[j].symbol_loc.y * h;
	game->thug[j].symbol_index = i;
}

int	patrol_init(t_root *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == 'T')
		{
			index_to_loc(i, j, game);
			j++;
		}
		i++;
	}
	return (0);
}
