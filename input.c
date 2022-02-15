/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 17:16:51 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	level_restart(t_root *game)
{
	game->status = NORMAL;
	free(game->map);
	game->map = ft_strdup(game->copy_map);
	playerlocation(game);
	game->m.select.pixel_loc.x = 0;
	game->i.max_o.symbol_index = 0;
	patrol_init(game);
	game->i.lady.pixels = ft_strchr(game->map, 'E');
	game->score = 0;
	game->restart = 1;
}

int	select_restart(int keypress, t_root *game)
{
	static int	k;

	if (keypress == D && !k && game->status == CONTINUE)
	{
		game->m.select.pixel_loc.x = 155;
		k = 1;
	}
	if (keypress == A && k && game->status == CONTINUE)
	{
		game->m.select.pixel_loc.x = 0;
		k = 0;
	}
	if (keypress == 36 && game->status == CONTINUE && !k)
		level_restart(game);
	if (keypress == 36 && game->status == CONTINUE && k)
		return_to_menu(game);
	return (1);
}

void	return_to_menu(t_root *game)
{
	int	x;
	int	y;

	x = game->m.menu.size.x;
	y = game->m.menu.size.y;
	game->restart = 1;
	free(game->map);
	game->close_level = 1;
	game->window = MAIN_MENU;
	mlx_destroy_window(game->mlx, game->mlxw);
	game->mlxw_m = mlx_new_window(game->mlx, x, y, "");
	game->m.select.pixel_loc.x = 220;
	game->m.select.pixel_loc.y = 425;
	mlx_hook(game->mlxw_m, 2, 0, &menu_select, game);
	mlx_loop_hook(game->mlx, &menu_render, game);
}

void	game_action(int keypress, t_root *game, int xx, int yy)
{
	int	line;
	int	i;

	i = ft_strchr(game->map, 'P') - game->map;
	line = game->symbolsize.x;
	if (keypress == W || keypress == U)
		if (game->map[xx + (line + 1) * (yy - 1)] != '1')
			if (game->map[xx + (line + 1) * (yy - 1)] != 'D')
				if (game->map[xx + (line + 1) * (yy - 1)] != 'E')
					move_wa(game, 'w', i);
	if (keypress == A || keypress == L)
		if (game->map[(xx - 1) + (line + 1) * yy] != '1')
			if (game->map[(xx - 1) + (line + 1) * yy] != 'E')
				move_wa(game, 'a', i);
	if (keypress == S || keypress == DN)
		if (game->map[xx + (line + 1) * (yy + 1)] != '1')
			if (game->map[xx + (line + 1) * (yy + 1)] != 'E')
				move_sd(game, 's', i);
	if (keypress == D || keypress == R)
		if (game->map[(xx + 1) + (line + 1) * yy] != '1')
			if (game->map[(xx + 1) + (line + 1) * yy] != 'E')
				move_sd(game, 'd', i);
	if (ft_strchr(game->map, 'P') == game->i.lady.pixels)
		if (!ft_strchr(game->map, 'C'))
			win(game);
}

int	action(int keypress, t_root *game)
{
	int	xx;
	int	yy;

	xx = game->i.max.symbol_loc.x;
	yy = game->i.max.symbol_loc.y;
	if (keypress == ESC)
		return_to_menu(game);
	if (game->status == NORMAL)
	{
		change_player_sprite(game, keypress);
		game_action(keypress, game, xx, yy);
	}
	if ((game->status == WIN || game->status == RECORD) && keypress == 36)
		next_level(game);
	if (game->status == CONTINUE)
		select_restart(keypress, game);
	return (0);
}
