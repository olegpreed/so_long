/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:32:56 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:10:05 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
}
