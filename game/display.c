/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:31:07 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:09:32 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_player_sprite(t_root *game, int keypress)
{
	if (keypress == W || keypress == U)
	{
		game->i.max_d.ref = image_ref(game, &(game->i.max_b));
		game->i.max.ref = image_ref(game, &(game->i.max_b));
	}
	if (keypress == A || keypress == L)
	{
		game->i.max_d.ref = image_ref(game, &(game->i.max_l));
		game->i.max.ref = image_ref(game, &(game->i.max_l));
	}
	if (keypress == S || keypress == DN)
	{
		game->i.max_d.ref = image_ref(game, &(game->i.max_d));
		game->i.max.ref = image_ref(game, &(game->i.max));
	}
	if (keypress == D || keypress == R)
	{
		game->i.max_d.ref = image_ref(game, &(game->i.max_r));
		game->i.max.ref = image_ref(game, &(game->i.max_r));
	}
}

void	fence(t_root *game, t_image *f)
{
	t_vector	xy;

	xy.x = game->pixelsize.x - game->i.wall.size.x * 2;
	xy.y = game->pixelsize.y - game->i.wall.size.y;
	while (xy.x <= game->pixelsize.x)
	{
		mlx_put_image_to_window(game->mlx, game->mlxw, f->ref, xy.x, xy.y);
		xy.x += game->i.wall.size.x;
	}
}

int	patrol(t_root *game)
{
	int			i;
	t_vector	xy;

	i = 0;
	patrol_move(game);
	while (i < game->t_count)
	{
		xy.x = game->thug[i].pixel_loc.x;
		xy.y = game->thug[i].pixel_loc.y - 10;
		print_image(game, &(game->thug[i]), xy, 0);
		i++;
	}
	return (0);
}

void	score(t_root *game)
{
	int		y;
	int		c;
	void	*m;
	void	*mw;

	m = game->mlx;
	mw = game->mlxw;
	y = game->pixelsize.y - 20;
	c = game->score;
	mlx_put_image_to_window(m, mw, game->i.s_num[c / 1000].ref, 4, y);
	mlx_put_image_to_window(m, mw, game->i.s_num[c % 1000 / 100].ref, 19, y);
	mlx_put_image_to_window(m, mw, game->i.s_num[c % 100 / 10].ref, 34, y);
	mlx_put_image_to_window(m, mw, game->i.s_num[c % 10].ref, 49, y);
}

void	hearts(t_root *game)
{
	static int	x[2];
	static int	y[2];
	t_vector	xy[2];
	static int	k;

	playerlocation(game);
	xy[0].x = x[0] + game->i.max.pixel_loc.x;
	xy[0].y = y[0] + game->i.max.pixel_loc.y;
	xy[1].x = x[1] + game->i.max.pixel_loc.x + 48;
	xy[1].y = y[1] + game->i.max.pixel_loc.y;
	if (y[0] > -70)
		if (y[0]-- > -60)
			print_image(game, &(game->i.heart), xy[0], 0);
	if (y[0] == -30)
		k = 1;
	else if (y[0] == -70)
		y[0] = 0;
	if (k && y[1] > -70)
		if (y[1]-- > -60)
			print_image(game, &(game->i.heart), xy[1], 0);
	if (k && y[1] == -70)
		y[1] = 0;
}
