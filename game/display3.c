/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:24:03 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:09:38 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
