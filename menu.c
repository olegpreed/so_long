/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:47:04 by oleg              #+#    #+#             */
/*   Updated: 2022/02/07 20:18:31 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	enter_level(t_root *game)
// {
// 	static int k;

// 	if (!k)
// 	{
// 		mlx_destroy_window(game->mlx, game->mlxw);
// 		start(game);
// 		patrol_init(game);
// 		k = 1;
// 	}
// 	mlx_hook(game->mlxw, 2, 0, &action, game);
// 	mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
// 	mlx_loop_hook(game->mlx, &map, game);
// 	return 0;
// }

void	score_number(t_root *game)
{
	int	i;
	
	if (game->close_menu == 2)
	{
		i = game->m.scores[game->m.lvl - 1];
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i / 1000].reference, 230, 360);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i % 1000 / 100].reference, 280, 360);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i % 100 / 10].reference, 330, 360);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i % 10].reference, 380, 360);
	}
}


void	level_number(t_root *game)
{
	int	i;
	t_image	bg;
	
	if (game->close_menu == 2)
	{
		bg.reference = mlx_new_image(game->mlx_m, game->m.menu.size.x, game->m.menu.size.y - 64);
		bg.pixels =mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, bg.reference, 0, 0);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.level.reference, 230, 100);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.score.reference, 230, 300);
		i = game->m.lvl;
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i / 10].reference, 275, 170);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.numbers[i % 10].reference, 315, 170);
	}
}

int menu_render(t_root *game)
{
	int	x;
	int	y;

	x = game->m.select.pixel_loc.x;
	y = game->m.select.pixel_loc.y;
	if (!game->close_menu)
	{
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.menu.reference, 0, 0);
		mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.select.reference, x, y);
	}
	else
	{
		level_number(game);
		score_number(game);
	}
	return (0);
}

void	level_select(t_root *game)
{
	t_image	bg;

	bg.reference = mlx_new_image(game->mlx_m, game->m.menu.size.x, game->m.menu.size.y - 64);
	bg.pixels =mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
	mlx_put_image_to_window(game->mlx_m, game->mlxw_m, bg.reference, 0, 0);
	mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.level.reference, 230, 100);
	mlx_put_image_to_window(game->mlx_m, game->mlxw_m, game->m.score.reference, 230, 300);
	game->close_menu = 2;
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
		game->close_menu = 1;
		mlx_destroy_window(game->mlx_m, game->mlxw_m);
		start(game);
		patrol_init(game);
		mlx_hook(game->mlxw, 2, 0, &action, game);
		mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
		mlx_loop_hook(game->mlx, &map, game);
	}
	return (0);
}

int	scores(t_root *game)
{
	char	*s;
	int		i;

	i = 0;
	game->fd = open("scoreboard", O_RDWR);
	if (game->fd == -1)
		return (1);
	while (i < 21)
	{
		s = get_next_line(game->fd);
		game->m.scores[i++] = ft_atoi(s);
		free(s);
	}
	close(game->fd);
	return (0);
}

int	ft_select(int keypress, t_root *game)
{
	static int	k;

	if (keypress == S && !k)
	{
		game->m.select.pixel_loc.y += 58;
		k = 1;
	}
	if (keypress == W && k)
	{
		game->m.select.pixel_loc.y -= 58;
		k = 0;
	}
	if (k && keypress == 36)
		exit_game();
	if (!k && keypress == 36)
	{
		scores(game);
		level_select(game);
		mlx_hook(game->mlxw_m, 2, 0, &select_lvl, game);
		k = 0;
	}
	return (0);
}

void	numbers_init(t_root *game)
{
	game->m.numbers[0].path = "./images/0.xpm";
	game->m.numbers[0].reference = image_ref(game, &(game->m.numbers[0]));
	game->m.numbers[1].path = "./images/1.xpm";
	game->m.numbers[1].reference = image_ref(game, &(game->m.numbers[1]));
	game->m.numbers[2].path = "./images/2.xpm";
	game->m.numbers[2].reference = image_ref(game, &(game->m.numbers[2]));
	game->m.numbers[3].path = "./images/3.xpm";
	game->m.numbers[3].reference = image_ref(game, &(game->m.numbers[3]));
	game->m.numbers[4].path = "./images/4.xpm";
	game->m.numbers[4].reference = image_ref(game, &(game->m.numbers[4]));
	game->m.numbers[5].path = "./images/5.xpm";
	game->m.numbers[5].reference = image_ref(game, &(game->m.numbers[5]));
	game->m.numbers[6].path = "./images/6.xpm";
	game->m.numbers[6].reference = image_ref(game, &(game->m.numbers[6]));
	game->m.numbers[7].path = "./images/7.xpm";
	game->m.numbers[7].reference = image_ref(game, &(game->m.numbers[7]));
	game->m.numbers[8].path = "./images/8.xpm";
	game->m.numbers[8].reference = image_ref(game, &(game->m.numbers[8]));
	game->m.numbers[9].path = "./images/9.xpm";
	game->m.numbers[9].reference = image_ref(game, &(game->m.numbers[9]));
}

void	level_init(t_root *game)
{
	// int	i;

	// i = 0;
	game->m.level.path = "./images/level.xpm";
	game->m.level.reference = image_ref(game, &(game->m.level));
	game->m.score.path = "./images/score.xpm";
	game->m.score.reference = image_ref(game, &(game->m.score));
	// while (i < 20)
	// 	game->m.lvl[i++] = 0;
	// game->m.lvl[0] = 1;
	game->m.lvl = 1;
	numbers_init(game);
}

void	menu(t_root *game)
{
	game->m.k = 0;
	game->close_menu = 0;
	game->close_level = 0;
	game->m.menu.path = "./images/menu.xpm";
	game->m.menu.reference = image_ref(game, &(game->m.menu));
	game->m.select.path = "./images/select.xpm";
	game->m.select.reference = image_ref(game, &(game->m.select));
	level_init(game);
	game->m.select.pixel_loc.x = 220;
	game->m.select.pixel_loc.y = 425;
	game->mlxw_m = mlx_new_window(game->mlx_m, game->m.menu.size.x, game->m.menu.size.y, "menu");
}
