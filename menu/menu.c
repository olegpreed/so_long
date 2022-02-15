/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:47:04 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:10:48 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	face_control(t_root *game, int x, int y)
{
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx;
	mlxw = game->mlxw_m;
	if (!(game->k))
	{
		mlx_put_image_to_window(mlx, mlxw, game->i.sec.ref, 385, 575);
		if (game->status == MENU)
			mlx_put_image_to_window(mlx, mlxw, game->i.max.ref, x, y);
		mlx_put_image_to_window(mlx, mlxw, game->m.rap[1].ref, x + 64, 577);
		mlx_put_image_to_window(mlx, mlxw, game->m.crazy[0].ref, x + 128, 577);
	}
	if (game->k)
	{
		if (game->status == MENU)
			mlx_put_image_to_window(mlx, mlxw, game->i.max2.ref, x, y);
		mlx_put_image_to_window(mlx, mlxw, game->i.sec2.ref, 385, 575);
		mlx_put_image_to_window(mlx, mlxw, game->m.rap[0].ref, x + 64, 577);
		mlx_put_image_to_window(mlx, mlxw, game->m.crazy[1].ref, x + 128, 577);
	}
}

void	menu_overlay(t_root *game, void *mlx, void *mlxw)
{
	int		x;
	int		y;
	void	*door;

	door = mlx_new_image(mlx, 64, 64);
	x = game->i.max.pixel_loc.x;
	x = game->i.max2.pixel_loc.x;
	y = game->i.max.pixel_loc.y;
	y = game->i.max2.pixel_loc.y;
	animation_cykle(game, 30);
	if (game->window == LEVEL_SELECT)
		mlx_put_image_to_window(mlx, mlxw, door, 447, 575);
	face_control(game, x, y);
	if (x == 447)
	{
		fading(door);
		mlx_put_image_to_window(mlx, mlxw, door, 447, 575);
	}
	mlx_put_image_to_window(mlx, mlxw, game->i.fence.ref, 512, 575);
	mlx_put_image_to_window(mlx, mlxw, game->i.fence.ref, 576, 575);
	mlx_put_image_to_window(mlx, mlxw, game->m.roof.ref, 447, 575);
}

int	menu_render(t_root *game)
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx;
	mlxw = game->mlxw_m;
	if (game->window == MAIN_MENU)
	{
		x = game->m.select.pixel_loc.x;
		y = game->m.select.pixel_loc.y;
		mlx_put_image_to_window(mlx, mlxw, game->m.menu.ref, 0, 0);
		menu_overlay(game, mlx, mlxw);
		mlx_put_image_to_window(mlx, mlxw, game->m.select.ref, x, y);
		if (game->cheat)
			mlx_put_image_to_window(mlx, mlxw, game->m.bullz.ref, 150, 10);
	}
	else if (game->window == LEVEL_SELECT)
	{
		menu_display_level(game);
		menu_display_score(game);
		if (game->status == MENU)
			player_entering(game);
	}
	return (0);
}

int	menu_select(int keypress, t_root *game)
{
	static int	k;

	if ((keypress == S || keypress == DN) && !k)
	{
		game->m.select.pixel_loc.y += 58;
		k = 1;
	}
	if ((keypress == W || keypress == U) && k)
	{
		game->m.select.pixel_loc.y -= 58;
		k = 0;
	}
	if (k && keypress == 36)
		exit_game();
	if (!k && keypress == 36)
	{
		game->window = LEVEL_SELECT;
		level_select_init(game);
		scores(game);
		mlx_hook(game->mlxw_m, 2, 0, &select_lvl, game);
	}
	cheat(keypress, game);
	return (0);
}

void	main_menu(t_root *game)
{
	int	x;
	int	y;

	game->window = MAIN_MENU;
	game->status = MENU;
	game->cheat = 0;
	menu_sprites_init(game);
	game->m.select.pixel_loc.x = 220;
	game->m.select.pixel_loc.y = 425;
	game->i.max.pixel_loc.x = 512;
	game->i.max2.pixel_loc.x = 512;
	game->i.max.pixel_loc.y = 575;
	game->i.max2.pixel_loc.y = 575;
	x = game->m.menu.size.x;
	y = game->m.menu.size.y;
	game->mlxw_m = mlx_new_window(game->mlx, x, y, "");
}
