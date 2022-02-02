/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:13:01 by oleg              #+#    #+#             */
/*   Updated: 2022/02/02 19:08:09 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_move_ws(t_root *game, int e, char a, int i)
{
	int	l;

	l = game->symbolsize.x;
	if (a == 'w' && game->map[e - l - 1] != 'T' && game->map[e - l - 1] != 'E')
	{
		if (game->map[e] != 'C' && game->map[e] != 'P')
			game->map[e] = '0';
		if (game->map[e - l - 1] != 'C' && game->map[e - l - 1] != 'C')
			game->map[e - l - 1] = 'T';
		game->thug[i].symbol_index -= (game->symbolsize.x + 1);
		game->thug[i].symbol_loc.y -= 1;
		game->thug[i].pixel_loc.y -= 64;
	}
	if (a == 's' && game->map[e + l + 1] != 'T' && game->map[e + l + 1] != 'E')
	{
		if (game->map[e] != 'C' && game->map[e] != 'P')
			game->map[e] = '0';
		if (game->map[e + l + 1] != 'C' && game->map[e + l + 1] != 'C')
			game->map[e + l + 1] = 'T';
		game->thug[i].symbol_index += (l + 1);
		game->thug[i].symbol_loc.y += 1;
		game->thug[i].pixel_loc.y += 64;
	}
}

void	final_move_rl(t_root *game, int e, char a, int i)
{
	if (a == 'r' && game->map[e + 1] != 'T' && game->map[e + 1] != 'E')
	{
		if (game->map[e] != 'C' && game->map[e] != 'P')
			game->map[e] = '0';
		if (game->map[e + 1] != 'C' && game->map[e + 1] != 'P')
			game->map[e + 1] = 'T';
		game->thug[i].symbol_index += 1;
		game->thug[i].symbol_loc.x += 1;
		game->thug[i].pixel_loc.x += 64;
	}
	if (a == 'l' && game->map[e - 1] != 'T' && game->map[e - 1] != 'E')
	{
		if (game->map[e] != 'C' && game->map[e] != 'P')
			game->map[e] = '0';
		if (game->map[e - 1] != 'C' && game->map[e - 1] != 'P')
			game->map[e - 1] = 'T';
		game->thug[i].symbol_index -= 1;
		game->thug[i].symbol_loc.x -= 1;
		game->thug[i].pixel_loc.x -= 64;
	}
}

void	final_move(t_root *game, int e, char a, int i)
{
	int	l;

	l = game->symbolsize.x;
	if (a == 'r' && game->map[e + 1] != 'D' && game->map[e + 1] != 'L')
		final_move_rl(game, e, a, i);
	if (a == 'l' && game->map[e - 1] != 'D' && game->map[e - 1] != 'L')
		final_move_rl(game, e, a, i);
	if (a == 'w' && game->map[e - l - 1] != 'D' && game->map[e - l - 1] != 'L')
		final_move_ws(game, e, a, i);
	if (a == 's' && game->map[e + l + 1] != 'D' && game->map[e + l + 1] != 'L')
		final_move_ws(game, e, a, i);
}

void	move(char a, t_root *game, int i)
{
	static int	j[100];
	int			e;

	e = game->thug[i].symbol_index;
	if (a == 'r' && game->map[e + 1] != '1' && j[i] == 20)
		final_move(game, e, 'r', i);
	if (a == 'l' && game->map[e - 1] != '1' && j[i] == 20)
		final_move(game, e, 'l', i);
	if (a == 'w' && game->map[e - game->symbolsize.x - 1] != '1' && j[i] == 20)
		final_move(game, e, 'w', i);
	if (a == 's' && game->map[e + game->symbolsize.x + 1] != '1' && j[i] == 20)
		final_move(game, e, 's', i);
	if (j[i] == 20)
		j[i] = 0;
	if (j[i] < 20)
		j[i]++;
}

int	check_enemy_vision(int i, int j, t_root *game, char *map)
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

void	fight(t_root *game, int i)
{
	int	m;

	m = game->i.max.symbol_index;
	if (game->thug[i].symbol_index == game->i.max.symbol_index)
	{
		game->map[m] = 'T';
		game->over = 1;
	}
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
		fight(game, i);
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
