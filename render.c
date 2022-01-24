/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/01/21 19:52:46 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	darken(t_root *game, t_image img, t_vector xy)
{
	mlx_put_image_to_window(game->mlx, game->mlxw, img.reference, xy.x, xy.y - 10);
}

void	crowd(t_root *game, t_vector xy, int i)
{
	mlx_put_image_to_window(game->mlx, game->mlxw, game->i.floor.reference, xy.x, xy.y);
	if (!game->k)
	{
		if ((game->random)[i] == 0)
		{
			xy.y += 2;
			darken(game, game->i.c.coke[0], xy);
		}
		else if ((game->random)[i] == 1)
			darken(game, game->i.c.naked[1], xy);
		else if ((game->random)[i] == 2)
			darken(game, game->i.c.hair[0], xy);
		else if ((game->random)[i] == 3)
			darken(game, game->i.c.goth[1], xy);
		else if ((game->random)[i] == 4)
			darken(game, game->i.c.rapper[0], xy);
		else if ((game->random)[i] == 5)
			darken(game, game->i.c.tired[1], xy);
	}
	else 
	{
		xy.y -= 1;
		//xy.x += 1;
		if ((game->random)[i] == 0)
			darken(game, game->i.c.coke[0], xy);
		else if ((game->random)[i] == 1)
			darken(game, game->i.c.naked[0], xy);
		else if ((game->random)[i] == 2)
			darken(game, game->i.c.hair[1], xy);
		else if ((game->random)[i] == 3)
			darken(game, game->i.c.goth[0], xy);
		else if ((game->random)[i] == 4)
			darken(game, game->i.c.rapper[1], xy);
		else if ((game->random)[i] == 5)
			darken(game, game->i.c.tired[0], xy);
	}
}	

void dj(t_root *game, t_vector xy)
{
	static int i;
	static int k;
	
	// if (game->symbolsize.x % 2 == 0)
	// 		xy.x = game->pixelsize.x / 2 - game->i.floor.size.x;
	// 	else
	// 		xy.x = (game->pixelsize.x - game->i.floor.size.x) / 2;
	if (!k)
	{
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.dj.reference, xy.x, 0);
		i++;
	}
	if (k)
	{
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.dj2.reference, xy.x, 0);
		i--;
	}
	if (i == 30)
		k = 1;
	if (i > 10 && i <= 20)
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.dj3.reference, xy.x, 0);
	if (i == 0)
		k = 0;
}

void	print_image(t_root *game, t_image *image, t_vector xy, int j)
{
	int		*i;
	t_image	*max;

	max = &(game->i.max);
	i = &(game->i.max.symbol_index);
	if (image == max && game->map[game->i.max.symbol_index] == 'C')
		game->map[game->i.max.symbol_index] = '0';
	if (image == max && game->map[*i] == 'E' && !ft_strchr(game->map, 'C'))
		exit_game();
	if (image != &(game->i.c.coke[0]))
		mlx_put_image_to_window(game->mlx, game->mlxw, image->reference, xy.x, xy.y);
	if (image == &(game->i.c.coke[0]))
		crowd(game, xy, j);
	if (image == &(game->i.wall) && xy.x == (game->pixelsize.x - 3 * game->i.floor.size.x))
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.door.reference, xy.x, xy.y);
}

int	sprite_float(void)
{
	static int i;
	static int k;
	static int count;

	if (count % 5 == 0)
	{
		if (i == 0)
		k = 0;
		if (i == 5)
			k = 1;
		if (!k)
		{
			i++;
		}
		if (k)
		{
			i--;
		}
	}
	count++;
	return (i);
}

void	symbol_to_image(t_root *game, t_vector xy, int i, int k)
{
	int	x;
	int y;
	static int j;
	
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	if ((game->map)[i] == '1' && (i - game->symbolsize.x) <= 0 && (game->map)[i - 1] != 'D' && !k)
		print_image(game, &(game->i.speak), xy, i);
	else if ((game->map)[i] == '1' && (i - game->symbolsize.x) <= 0 && (game->map)[i - 1] != 'D' && k)
		print_image(game, &(game->i.speak2), xy, i);
	else if ((game->map)[i] == 'D')
		dj(game, xy);  
	else if ((game->map)[i] == '1' && (i - game->symbolsize.x) > 0 && ((x + 1) * y) - i > (x + 1))
		print_image(game, &(game->i.c.coke[0]), xy, i);
	else if ((game->map)[i] == '1' && (i - game->symbolsize.x) > 0 && ((x + 1) * y) - i <= (x + 1))
		print_image(game, &(game->i.wall), xy, i);
	else if ((game->map)[i] == '0')
		print_image(game, &(game->i.floor), xy, i);
	else if ((game->map)[i] == 'P')
	{
		print_image(game, &(game->i.floor), xy, i);
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.max.reference, xy.x, xy.y - 10);
	}
	else if ((game->map)[i] == 'C')
	{
		print_image(game, &(game->i.floor), xy, i);
		xy.y -= 25;
		print_image(game, &(game->i.shadow_b), xy, i);
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.beer.reference, xy.x, xy.y - j);
	}
	else if ((game->map)[i] == 'E')
	{
		print_image(game, &(game->i.floor), xy, i);
		j = sprite_float();
		xy.y -= 10;
		print_image(game, &(game->i.lady), xy, i);
	}
}

void	paint_bg(t_image *bg, t_root *game)
{
	int	x;
	int y;
	static int k;
	int g;
	static int b = 0xFF;
	static int t;
	static int r = 0xFF;
	
	
	x = 0;
	y = 0;
	t = 0;
	g = 0x0;
	
	while (y < game->pixelsize.y)
	{
		while (x < game->pixelsize.x)
		{	
			my_mlx_pixel_put(bg, x, y, create_trgb(t, r, g, b));
			x++;
		}
		x = 0;
		y++;	
	}
	if (r == 0xFF)
		k = 1;
	if (r == 0x00)
		k = 0;
	if (!k) 
	{
		r += 3;
		b++;
	}
	else
	{
		r -= 3;
		b--;
	}
	
}

void	background(t_root *game)
{
	t_image bg;
	bg.reference = mlx_new_image(game->mlx, game->pixelsize.x, game->pixelsize.y);
	bg.pixels =mlx_get_data_addr(bg.reference, &(bg.bits_per_pixel), &(bg.line_length), &(bg.endian));
	paint_bg(&bg, game);
	mlx_put_image_to_window(game->mlx, game->mlxw, bg.reference, 0, 0);
}

int	map(t_root *game)
{	
	t_vector	xy;
	int			i;
	t_image		*player;
	static int	k;
	static int count;

	game->k = k;
	player = &(game->i.max);
	xy.x = 0;
	xy.y = 0;
	i = 0;
	//background(game);  
	game->map[game->symbolsize.x / 2 - 1] = 'D';
	while ((game->map)[i])
	{
		if ((game->map)[i] == '\n')
		{
			xy.x = 0;
			xy.y += game->i.floor.size.y;
		}
		else
		{
			symbol_to_image(game, xy, i, k);
			xy.x += game->i.floor.size.x;
		}
		i++;
	}
	if (count == 15)
		k = 1;
	if (count == 0)
		k = 0;
	if (!k)
		count++;
	else 
		count--;
	//print_image(game, player, game->i.max.pixel_loc, i);
	 // remake initial string -> then insert dj, bodyguards, and all the rest
	return (1);
}
