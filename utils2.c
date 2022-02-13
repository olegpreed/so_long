/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:15:02 by oleg              #+#    #+#             */
/*   Updated: 2022/02/13 14:18:03 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_cykle(t_root *game, int speed)
{
	static int	count;
	static int	k;

	if (count == speed)
		k = 1;
	if (count == 0)
		k = 0;
	if (!k)
		count++;
	else
		count--;
	game->k = k;
}

int	symbol_loc(t_root *game, int line)
{
	int	x;
	int	y;

	x = game->i.max.symbol_loc.x;
	y = game->i.max.symbol_loc.y;
	return (x + y * (line + 1));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image *bg, int x, int y, int color)
{
	char	*dst;

	dst = bg->pixels + (y * bg->line_length + x * (bg->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_game(void)
{
	exit(0);
	return (1);
}
