/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:13:14 by oleg              #+#    #+#             */
/*   Updated: 2022/02/14 18:35:18 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_init(t_root *game)
{
	int	i;

	i = game->t_count;
	game->thug = (t_image *)malloc(i * sizeof(t_image));
	if (game->thug == 0)
		printf("t_count = %d\n ,malloc !\n", game->t_count);
}

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
