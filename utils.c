/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:31:28 by preed             #+#    #+#             */
/*   Updated: 2022/02/03 20:51:46 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	just_black(t_image *bg, t_root *game)
{
	int	x;
	int y;
	static int r;
	static int g;
	static int b;
	static int t = 0xA0;

	y = 0;
	x = 0;
	while (y < game->i.floor.size.y)
	{
		while (x < game->pixelsize.x)
		{	
			my_mlx_pixel_put(bg, x, y, create_trgb(t, r, g, b));
			x++;
		}
		x = 0;
		y++;
	}
	if (game->over == 1 && t < 0xFA)
		t += 3;
}

void	black(t_image *bg, t_root *game)
{
	int	x;
	int y;
	static int r;
	static int g;
	static int b;
	static int t = 0xFF;

	y = 0;
	x = 0;
	while (y < game->pixelsize.y - game->i.floor.size.y)
	{
		while (x < game->pixelsize.x)
		{	
			my_mlx_pixel_put(bg, x, y, create_trgb(t, r, g, b));
			x++;
		}
		x = 0;
		y++;
	}
	if (t)
		t -= 3;
}

// void	background(t_root *game)
// {
// 	t_image	bg;

// 	bg.reference = mlx_new_image(game->mlx, game->pixelsize.x, game->pixelsize.y - game->i.floor.size.y);
// 	bg.pixels =mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
// 	paint_bg(&bg, game);
// 	mlx_put_image_to_window(game->mlx, game->mlxw, bg.reference, 0, 0);
// }

void	fade_to_black(t_root *game)
{
	t_image	bg;

	bg.reference = mlx_new_image(game->mlx, game->pixelsize.x, game->pixelsize.y - game->i.floor.size.y);
	bg.pixels =mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
	black(&bg, game);
	mlx_put_image_to_window(game->mlx, game->mlxw, bg.reference, 0, 0);
}


void	animation_cykle(t_root *game)
{
	static int	count;
	static int	k;

	if (count == 10)
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

void darken(t_root *game)
{
	t_image	bg;

	bg.reference = mlx_new_image(game->mlx, game->pixelsize.x, game->i.floor.size.y);
	bg.pixels = mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
	just_black(&bg, game);
	mlx_put_image_to_window(game->mlx, game->mlxw, bg.reference, 0, game->pixelsize.y - game->i.floor.size.y);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image *bg, int x, int y, int color)
{
	char	*dst;

	dst = bg->pixels + (y * bg->line_length + x * (bg->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}