/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:48:58 by oleg              #+#    #+#             */
/*   Updated: 2022/02/14 15:45:54 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_entering(t_root *game)
{
	if (game->i.max.pixel_loc.x > 447)
	{
		game->i.max.pixel_loc.x--;
		game->i.max2.pixel_loc.x--;
	}
	else
	{
		game->i.max.ref = game->i.max_b.ref;
		game->i.max2.ref = game->i.max_b.ref;
		game->i.max.pixel_loc.y--;
		game->i.max2.pixel_loc.y--;
	}
}

void	level_select_init(t_root *game)
{
	game->m.level.path = "./images/level.xpm";
	game->m.level.ref = image_ref(game, &(game->m.level));
	game->m.score.path = "./images/score.xpm";
	game->m.score.ref = image_ref(game, &(game->m.score));
	game->m.lvl = 1;
	num_init(game);
}

void	menu_display_score(t_root *game)
{
	int		i;
	int		j[4];
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx_m;
	mlxw = game->mlxw_m;
	i = game->m.scores[game->m.lvl - 1];
	j[0] = i / 1000;
	j[1] = i % 1000 / 100;
	j[2] = i % 100 / 10;
	j[3] = i % 10;
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[0]].ref, 230, 410);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[1]].ref, 280, 410);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[2]].ref, 330, 410);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[3]].ref, 380, 410);
}

void	menu_display_level(t_root *game)
{
	int		i;
	void	*bg;
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx_m;
	mlxw = game->mlxw_m;
	mlx_put_image_to_window(mlx, mlxw, game->m.menu.ref, 0, 0);
	menu_overlay(game, mlx, mlxw);
	bg = mlx_new_image(mlx, game->m.menu.size.x, game->m.menu.size.y - 64);
	mlx_put_image_to_window(mlx, mlxw, bg, 0, 0);
	mlx_put_image_to_window(mlx, mlxw, game->m.level.ref, 230, 150);
	mlx_put_image_to_window(mlx, mlxw, game->m.score.ref, 230, 350);
	i = game->m.lvl;
	mlx_put_image_to_window(mlx, mlxw, game->m.num[i / 10].ref, 275, 220);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[i % 10].ref, 315, 220);
}

int	select_lvl(int keypress, t_root *game)
{
	if ((keypress == D || keypress == R) && game->m.lvl != 21)
		game->m.lvl++;
	else if ((keypress == A || keypress == L) && game->m.lvl != 1)
		game->m.lvl--;
	else if ((keypress == D || keypress == R) && game->m.lvl == 21)
		game->m.lvl = 1;
	else if ((keypress == A || keypress == L) && game->m.lvl == 1)
		game->m.lvl = 21;
	if (keypress == 36)
	{
		preparation(game);
		game->window = GAME;
		game->close_level = 0;
		mlx_destroy_window(game->mlx_m, game->mlxw_m);
		start(game, 0);
		patrol_init(game);
		mlx_hook(game->mlxw, 2, 0, &action, game);
		mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
		mlx_loop_hook(game->mlx, &map, game);
	}
	return (0);
}
