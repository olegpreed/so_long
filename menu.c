/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:47:04 by oleg              #+#    #+#             */
/*   Updated: 2022/02/05 22:08:48 by oleg             ###   ########.fr       */
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
	return (0);
}

int	select(int keypress, t_root *game)
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
		game->close_menu = 1;
		k = 0;
		mlx_destroy_window(game->mlx_m, game->mlxw_m);
		start(game);
		patrol_init(game);
		mlx_hook(game->mlxw, 2, 0, &action, game);
		mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
		mlx_loop_hook(game->mlx, &map, game);
	}
	return (0);
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
	game->m.select.pixel_loc.x = 220;
	game->m.select.pixel_loc.y = 425;
	game->mlxw_m = mlx_new_window(game->mlx_m, game->m.menu.size.x, game->m.menu.size.y, "menu");
}
