/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/02/10 17:12:34 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_crowd(t_root *game, t_image img, t_vector xy)
{
	xy.y -= 10;
	mlx_put_image_to_window(game->mlx, game->mlxw, img.ref, xy.x, xy.y);
}

void	crowd_2(t_root *game, t_vector xy, int i)
{
	xy.y -= 1;
	if ((game->random)[i] == 0)
		put_crowd(game, game->i.c.coke[0], xy);
	else if ((game->random)[i] == 1)
		put_crowd(game, game->i.c.naked[0], xy);
	else if ((game->random)[i] == 2)
		put_crowd(game, game->i.c.hair[1], xy);
	else if ((game->random)[i] == 3)
		put_crowd(game, game->i.c.goth[0], xy);
	else if ((game->random)[i] == 4)
		put_crowd(game, game->i.c.rapper[1], xy);
	else if ((game->random)[i] == 5)
		put_crowd(game, game->i.c.tired[0], xy);
}

void	crowd_1(t_root *game, t_vector xy, int i)
{
	print_image(game, &(game->i.floor), xy, 0);
	if (!game->k)
	{
		if ((game->random)[i] == 0)
		{
			xy.y += 2;
			put_crowd(game, game->i.c.coke[0], xy);
		}
		else if ((game->random)[i] == 1)
			put_crowd(game, game->i.c.naked[1], xy);
		else if ((game->random)[i] == 2)
			put_crowd(game, game->i.c.hair[0], xy);
		else if ((game->random)[i] == 3)
			put_crowd(game, game->i.c.goth[1], xy);
		else if ((game->random)[i] == 4)
			put_crowd(game, game->i.c.rapper[0], xy);
		else if ((game->random)[i] == 5)
			put_crowd(game, game->i.c.tired[1], xy);
	}
	else
		crowd_2(game, xy, i);
}	

void	fence(t_root *game, t_image *f)
{
	t_vector xy;

	xy.x = game->pixelsize.x - game->i.wall.size.x * 2;
	xy.y = game->pixelsize.y - game->i.wall.size.y + 10;
	while (xy.x <= game->pixelsize.x)
	{
		mlx_put_image_to_window(game->mlx, game->mlxw, f->ref, xy.x, xy.y);
		xy.x += game->i.wall.size.x;
	}
}

void	print_image(t_root *game, t_image *image, t_vector xy, int j)
{
	int		x;
	int		y;
	int		l;

	l = game->i.floor.size.x;
	x = xy.x;
	y = xy.y;
	if (image != &(game->i.c.coke[0]))
		mlx_put_image_to_window(game->mlx, game->mlxw, image->ref, x, y);
	if (image == &(game->i.c.coke[0]))
		crowd_1(game, xy, j);
	if (image == &(game->i.wall) && x == (game->pixelsize.x - 3 * l))
	{
		if (game->i.max_o.symbol_index != 42)
			print_image(game, &(game->i.door), xy, 0);
		else
			print_image(game, &(game->i.door_o), xy, 0);
	}
}

void	dj(t_root *game, t_vector xy)
{
	static int	i;
	static int	k;

	xy.y = 0;
	if (!k)
	{
		print_image(game, &(game->i.dj), xy, 0);
		i++;
	}
	if (k)
	{
		print_image(game, &(game->i.dj2), xy, 0);
		i--;
	}
	if (i == 30)
		k = 1;
	if (i > 10 && i <= 20)
		print_image(game, &(game->i.dj3), xy, 0);
	if (i == 0)
		k = 0;
}

int	sprite_float(void)
{
	static int	i;
	static int	k;
	static int	count;

	if (count % 5 == 0)
	{
		if (i == 0)
			k = 0;
		if (i == 5)
			k = 1;
		if (!k)
			i++;
		if (k)
			i--;
	}
	count++;
	return (i);
}

int	lady(t_root *game, t_vector xy, int i)
{
	print_image(game, &(game->i.floor), xy, i);
	xy.y -= 10;
	if (!game->k)
		xy.y += 3;
	if (*game->i.lady.pixels == 'E')
		print_image(game, &(game->i.lady), xy, i);
	if (*game->i.lady.pixels == 'L')
		print_image(game, &(game->i.lady_w), xy, i);
	return (sprite_float());
}

void	collectible(t_root *game, t_vector xy, int i, int j)
{
	print_image(game, &(game->i.floor_c), xy, i);
	xy.y -= 25;
	print_image(game, &(game->i.shadow_b), xy, i);
	xy.y -= j;
	print_image(game, &(game->i.beer), xy, 0);
}

void	player(t_root *game, t_vector xy, int i)
{
	print_image(game, &(game->i.floor), xy, i);
	xy.y -= 10;
	print_image(game, &(game->i.max), xy, 0);
}

void	walls(t_root *game, t_vector xy, int i, int k)
{
	int			x;
	int			y;
	char		*map;

	map = game->map;
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	if (map[i] == '1' && (i - x) <= 0 && map[i - 1] != 'D' && !k)
		print_image(game, &(game->i.speak), xy, i);
	else if (map[i] == '1' && (i - x) <= 0 && map[i - 1] != 'D' && k)
		print_image(game, &(game->i.speak2), xy, i);
	else if (map[i] == 'D')
		dj(game, xy);
	else if (map[i] == '1' && (i - x) > 0 && ((x + 1) * y) - i > (x + 1))
		print_image(game, &(game->i.c.coke[0]), xy, i);
	else if (map[i] == '1' && (i - x) > 0 && ((x + 1) * y) - i <= (x + 1))
		print_image(game, &(game->i.wall), xy, i);
}

void	symbol_to_image(t_root *game, t_vector xy, int i, int k)
{
	static int	j;

	if (game->map[i] == '1' || game->map[i] == 'D')
		walls(game, xy, i, k);
	else if (game->map[i] == '0' || game->map[i] == 'T')
		print_image(game, &(game->i.floor), xy, i);
	else if (game->map[i] == 'P')
		player(game, xy, i);
	else if (game->map[i] == 'C')
		collectible(game, xy, i, j);
	else if (game->map[i] == 'E' || game->map[i] == 'L')
		j = lady(game, xy, i);
}

int	patrol(t_root *game)
{
	int			i;
	t_vector	xy;

	i = 0;
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
	int	x;
	int	y;
	int	c;

	x = 4;
	y = game->pixelsize.y - 20;
	c = game->score;
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.s_num[c / 1000].ref, x, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.s_num[c % 1000 / 100].ref, x + 15, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.s_num[c % 100 / 10].ref, x + 30, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.s_num[c % 10].ref, x + 45, y);
}

void hearts(t_root *game)
{
	static int	x[2];
	static int	y[2];
	int			xx[2];
	int			yy[2];
	static int k;

	playerlocation(game);
	xx[0] = x[0] + game->i.max.pixel_loc.x;
	yy[0] = y[0] + game->i.max.pixel_loc.y;
	xx[1] = x[1] + game->i.max.pixel_loc.x + 48;
	yy[1] = y[1] + game->i.max.pixel_loc.y;
	if (y[0] > -70)
	{
		if (y[0] > -60)
			mlx_put_image_to_window(game->mlx, game->mlxw, game->i.heart.ref, xx[0], yy[0]);
		y[0]--;
	}
	if (y[0] == -30)
		k = 1;
	else if (y[0] == -70)
		y[0] = 0;
	if (k && y[1] > -69)
	{
		if (y[1] > -59)
			mlx_put_image_to_window(game->mlx, game->mlxw, game->i.heart.ref, xx[1], yy[1]);
		y[1]--;
	}
	else if (k && y[1] == -69)
		y[1] = 0;
}

int	map(t_root *game)
{	
	t_vector	xy;
	int			i;
	t_image		*player;

	if (!game->close_level)
	{
		patrol_move(game);
		player = &(game->i.max);
		xy.x = 0;
		xy.y = 0;
		i = -1;
		while ((game->map)[++i])
		{
			if ((game->map)[i] == '\n')
			{
				xy.x = 0;
				xy.y += game->i.floor.size.y;
			}
			else
			{
				symbol_to_image(game, xy, i, game->k);
				xy.x += game->i.floor.size.x;
			}
		}
		fence(game, &(game->i.fence));
		patrol(game);
		score(game);
		darken(game);
		if (game->over == 21 || game->over == 100)
			hearts(game);
		if (game->over == 100)
			display_score(game);
		if (game->over == 1)
			game_over(game);
		animation_cykle(game);
	}
	return (1);
}
