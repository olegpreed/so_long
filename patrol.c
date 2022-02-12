/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:13:01 by oleg              #+#    #+#             */
/*   Updated: 2022/02/10 22:26:20 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_2(int i, int j, t_root *game, int ty)
{
	int	my;

	my = game->i.max.symbol_loc.y;
	if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && my > ty)
	{
		while (ty < my)
		{
			if (game->map[j] == '1')
				return (0);
			j -= (game->symbolsize.x + 1);
			ty += 1;
		}
		return (3);
	}
	else
	{
		while (my < ty)
		{
			if (game->map[j] == '1')
				return (0);
			j += (game->symbolsize.x + 1);
			my += 1;
		}
		return (4);
	}
}

int	check_1(int e, int j, char *map, int n)
{
	if (n == 1)
	{
		while (e < j)
			if (map[e++] == '1')
				return (0);
		return (1);
	}
	if (n == 2)
	{
		while (j < e)
			if (map[j++] == '1')
				return (0);
		return (2);
	}
	return (0);
}

int	check_enemy_vision(int i, int j, t_root *game)
{
	int	my;
	int	ty;
	int	e;

	my = game->i.max.symbol_loc.y;
	ty = game->thug[i].symbol_loc.y;
	e = game->thug[i].symbol_index;
	if (j - e < game->symbolsize.x + 1 && j - e > 0)
		return (check_1(e, j, game->map, 1));
	else if (e - j < game->symbolsize.x + 1 && e - j > 0)
		return (check_1(e, j, game->map, 2));
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && my > ty)
		return (check_2(i, j, game, ty));
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && ty > my)
		return (check_2(i, j, game, ty));
	return (0);
}

void	fight(t_root *game, int i, int j)
{
	if (game->thug[i].symbol_index == j)
	{
		game->map[j] = 'T';
		game->status = OVER;
	}
}

int	patrol_move(t_root *game)
{
	int			i;
	int			k[30];
	static int	e[30];

	i = 0;
	if (game->status == NORMAL)
	{
		while (i < game->t_count)
		{
			fight(game, i, game->i.max.symbol_index);
			k[i] = check_enemy_vision(i, game->i.max.symbol_index, game);
			if (k[i])
				e[i] = k[i];
			i++;
		}
		i = -1;
		while (++i < game->t_count)
			movement(game, i, e[i]);
	}
	i = 0;
	if (game->status != NORMAL)
		while (i < game->t_count)
			e[i++] = 0;
	return (0);
}
