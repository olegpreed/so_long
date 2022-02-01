/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:13:01 by oleg              #+#    #+#             */
/*   Updated: 2022/02/02 00:19:34 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move(char a, t_root *game, int i)
{
	static int j[100];
	int e = game->thug[i].symbol_index;
	//printf("index = %d, move = %c\n", i, a);
		if (a == 'r' && game->map[e + 1] != '1' && j[i] == 20) 
		{
			game->thug[i].symbol_index += 1;
			game->thug[i].symbol_loc.x += 1;
			game->thug[i].pixel_loc.x += 64; 
		}
		if (a == 'l' && game->map[e - 1] != '1' && j[i] == 20)
		{
			game->thug[i].symbol_index -= 1;
			game->thug[i].symbol_loc.x -= 1;
			game->thug[i].pixel_loc.x -= 64;
		}
		if (a == 'w' && game->map[e - game->symbolsize.x - 1] != '1'  && j[i] == 20)
		{
			game->thug[i].symbol_index -= (game->symbolsize.x + 1);
			game->thug[i].symbol_loc.y -= 1;
			game->thug[i].pixel_loc.y -= 64;
		}
		if (a == 's' && game->map[e + game->symbolsize.x + 1] != '1' && j[i] == 20)
		{
			game->thug[i].symbol_index += (game->symbolsize.x + 1);
			game->thug[i].symbol_loc.y += 1;
			game->thug[i].pixel_loc.y += 64;
		}
	if (j[i] == 20)
		j[i] = 0;
	if (j[i] < 20)
		j[i]++;
}

int check_enemy_vision(int i, int j, t_root *game, char *map)
{
	int my = game->i.max.symbol_loc.y;
	int ty = game->thug[i].symbol_loc.y;
	int e = game->thug[i].symbol_index;
	if (j - e < game->symbolsize.x + 1 && j - e > 0)
	{
		while (e < j)
			if (map[e++] == '1')
				return (0);
		return (1);
	}
	else if (e - j < game->symbolsize.x + 1 && e - j > 0)
	{
		while (j < e)
			if (map[j++] == '1')
				return (0);
		return (2);
	}
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && my > ty)
	{
		while (ty < my)
		{
			if (map[j] == '1')
				return (0);
			j -= (game->symbolsize.x + 1);
			ty += 1;
		}
		return (3);
	}
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && ty > my)
	{
		while (my < ty)
		{
			if (map[j] == '1')
				return (0);
			j += (game->symbolsize.x + 1);
			my += 1;
		}
		return (4);
	}
	return (0);
}

void	movement(t_root *game, int i, int e)
{
	if (e == 1)
		move('r', game, i);
	if (e == 2)
		move('l', game, i);
	if (e == 3)
		move('s', game, i);
	if (e == 4)
		move('w', game, i);
	if (e == 0)
		move('n', game, i);
}

int	patrol_move(t_root *game)
{
	int			j;
	int			i;
	int			k[100];
	static int	e[100];

	i = 0;
	j = game->i.max.symbol_index;
	while (i < game->t_count)
	{
		k[i] = check_enemy_vision(i, j, game, game->map);
		if (k[i])
			e[i] = k[i];
		i++;
	}
	i = -1;
	while (++i < game->t_count)
		movement(game, i, e[i]);
	return (0);
}