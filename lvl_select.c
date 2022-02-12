/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:48:58 by oleg              #+#    #+#             */
/*   Updated: 2022/02/10 18:12:46 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	num_init(t_root *game)
{
	game->m.num[0].path = "./images/0.xpm";
	game->m.num[0].ref = image_ref(game, &(game->m.num[0]));
	game->m.num[1].path = "./images/1.xpm";
	game->m.num[1].ref = image_ref(game, &(game->m.num[1]));
	game->m.num[2].path = "./images/2.xpm";
	game->m.num[2].ref = image_ref(game, &(game->m.num[2]));
	game->m.num[3].path = "./images/3.xpm";
	game->m.num[3].ref = image_ref(game, &(game->m.num[3]));
	game->m.num[4].path = "./images/4.xpm";
	game->m.num[4].ref = image_ref(game, &(game->m.num[4]));
	game->m.num[5].path = "./images/5.xpm";
	game->m.num[5].ref = image_ref(game, &(game->m.num[5]));
	game->m.num[6].path = "./images/6.xpm";
	game->m.num[6].ref = image_ref(game, &(game->m.num[6]));
	game->m.num[7].path = "./images/7.xpm";
	game->m.num[7].ref = image_ref(game, &(game->m.num[7]));
	game->m.num[8].path = "./images/8.xpm";
	game->m.num[8].ref = image_ref(game, &(game->m.num[8]));
	game->m.num[9].path = "./images/9.xpm";
	game->m.num[9].ref = image_ref(game, &(game->m.num[9]));
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
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[0]].ref, 230, 360);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[1]].ref, 280, 360);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[2]].ref, 330, 360);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[j[3]].ref, 380, 360);
}

void	menu_display_level(t_root *game)
{
	int		i;
	void	*bg;
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx_m;
	mlxw = game->mlxw_m;
	bg = mlx_new_image(mlx, game->m.menu.size.x, game->m.menu.size.y - 64);
	mlx_put_image_to_window(game->mlx_m, game->mlxw_m, bg, 0, 0);
	mlx_put_image_to_window(mlx, mlxw, game->m.level.ref, 230, 100);
	mlx_put_image_to_window(mlx, mlxw, game->m.score.ref, 230, 300);
	i = game->m.lvl;
	mlx_put_image_to_window(mlx, mlxw, game->m.num[i / 10].ref, 275, 170);
	mlx_put_image_to_window(mlx, mlxw, game->m.num[i % 10].ref, 315, 170);
}

int	select_lvl(int keypress, t_root *game)
{
	if (keypress == D && game->m.lvl != 21)
		game->m.lvl++;
	else if (keypress == A && game->m.lvl != 1)
		game->m.lvl--;
	else if (keypress == D && game->m.lvl == 21)
		game->m.lvl = 1;
	else if (keypress == A && game->m.lvl == 1)
		game->m.lvl = 21;
	if (keypress == 36)
	{
		preparation(game);
		game->window = GAME;
		game->close_level = 0;
		mlx_destroy_window(game->mlx_m, game->mlxw_m);
		start(game);
		patrol_init(game);
		mlx_hook(game->mlxw, 2, 0, &action, game);
		mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
		mlx_loop_hook(game->mlx, &map, game);
	}
	return (0);
}
