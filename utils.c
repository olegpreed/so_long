/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:31:28 by preed             #+#    #+#             */
/*   Updated: 2022/02/12 11:48:10 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	just_black(t_image *bg, t_root *game)
{
	int			x;
	int			y;
	static int	t = 0xA0;

	y = 0;
	x = 0;
	while (y < game->i.floor.size.y)
	{
		while (x < game->pixelsize.x)
		{	
			my_mlx_pixel_put(bg, x, y, create_trgb(t, 0x00, 0x00, 0x00));
			x++;
		}
		x = 0;
		y++;
	}
	if (game->status == OVER && t < 0xFA)
		t += 3;
}

void	black(t_image *bg, t_root *game)
{
	int			x;
	int			y;
	static int	t = 0xFF;

	y = 0;
	x = 0;
	while (y < game->pixelsize.y - game->i.floor.size.y)
	{
		while (x < game->pixelsize.x)
		{	
			my_mlx_pixel_put(bg, x, y, create_trgb(t, 0x00, 0x00, 0x00));
			x++;
		}
		x = 0;
		y++;
	}
	if (t)
		t -= 3;
}

void	fade_to_black(t_root *game)
{
	t_image	bg;
	int		y;
	int		*p;

	p = &(bg.bits_per_pixel);
	y = game->pixelsize.y - game->i.floor.size.y;
	bg.ref = mlx_new_image(game->mlx, game->pixelsize.x, y);
	bg.pixels = mlx_get_data_addr(bg.ref, p, &(bg.line_length), &(bg.endian));
	black(&bg, game);
	mlx_put_image_to_window(game->mlx, game->mlxw, bg.ref, 0, 0);
}

void	darken(t_root *game)
{
	t_image	bg;
	int		*p;

	p = &(bg.bits_per_pixel);
	bg.ref = mlx_new_image(game->mlx, game->pixelsize.x, game->i.floor.size.y);
	bg.pixels = mlx_get_data_addr(bg.ref, p, &(bg.line_length), &(bg.endian));
	just_black(&bg, game);
	mlx_img(game, bg.ref, 0, game->pixelsize.y - game->i.floor.size.y);
}
