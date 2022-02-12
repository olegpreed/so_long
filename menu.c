/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:47:04 by oleg              #+#    #+#             */
/*   Updated: 2022/02/12 16:23:31 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	menu_render(t_root *game)
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx_m;
	mlxw = game->mlxw_m;
	x = game->m.select.pixel_loc.x;
	y = game->m.select.pixel_loc.y;
	if (game->window == MAIN_MENU)
	{
		mlx_put_image_to_window(mlx, mlxw, game->m.menu.ref, 0, 0);
		mlx_put_image_to_window(mlx, mlxw, game->m.select.ref, x, y);
		if (game->cheat)
			mlx_put_image_to_window(mlx, mlxw, game->m.bullz.ref, 150, 10);
	}
	else if (game->window == LEVEL_SELECT)
	{
		menu_display_level(game);
		menu_display_score(game);
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

void	cheat(int keypress, t_root *game)
{
	static int	c;

	if (keypress == 11)
		c++;
	else if (keypress == 32 && c == 1)
		c++;
	else if (keypress == 37 && c == 2)
		c++;
	else if (keypress == 37 && c == 3)
		c++;
	else if (keypress == 6 && c == 4)
		c++;
	else
		c = 0;
	if (c == 5)
		game->cheat = 1;
}

int	menu_select(int keypress, t_root *game)
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
	game->cheat = 0;
	game->m.menu.path = "./images/menu.xpm";
	game->m.menu.ref = image_ref(game, &(game->m.menu));
	game->m.select.path = "./images/select.xpm";
	game->m.select.ref = image_ref(game, &(game->m.select));
	game->m.bullz.path = "./images/bullz.xpm";
	game->m.bullz.ref = image_ref(game, &(game->m.bullz));
	game->m.select.pixel_loc.x = 220;
	game->m.select.pixel_loc.y = 425;
	x = game->m.menu.size.x;
	y = game->m.menu.size.y;
	game->mlxw_m = mlx_new_window(game->mlx_m, x, y, "");
}
