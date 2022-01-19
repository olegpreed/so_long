/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/01/19 20:17:14 by preed            ###   ########.fr       */
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
	if ((game->random)[i] == 0)
		darken(game, game->i.coke, xy);
	else if ((game->random)[i] == 1)
		darken(game, game->i.naked, xy);
	else if ((game->random)[i] == 2)
		darken(game, game->i.hair, xy);
	else if ((game->random)[i] == 3)
		darken(game, game->i.goth, xy);
	else if ((game->random)[i] == 4)
		darken(game, game->i.rapper, xy);
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
	mlx_put_image_to_window(game->mlx, game->mlxw, image->reference, xy.x, xy.y);
	if (image == &(game->i.coke))
		crowd(game, xy, j);
	if (image == &(game->i.wall) && xy.x == (game->pixelsize.x - 3 * game->i.floor.size.x))
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.door.reference, xy.x, xy.y);
	if (image == &(game->i.speak))
	{
		if (game->symbolsize.x % 2 == 0)
			xy.x = game->pixelsize.x / 2 - game->i.floor.size.x;
		else
			xy.x = (game->pixelsize.x - game->i.floor.size.x) / 2;
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.dj.reference, xy.x, xy.y);
	}
}

void	symbol_to_image(t_root *game, t_vector xy, int i)
{
	int	x;
	int y;
	
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	if ((game->map)[i] == '1' && (i - game->symbolsize.x) <= 0)
		print_image(game, &(game->i.speak), xy, i);
	else if ((game->map)[i] == '1' && (i - game->symbolsize.x) > 0 && ((x + 1) * y) - i > (x + 1))
		print_image(game, &(game->i.coke), xy, i);
	else if ((game->map)[i] == '1' && (i - game->symbolsize.x) > 0 && ((x + 1) * y) - i <= (x + 1))
		print_image(game, &(game->i.wall), xy, i);
	else if ((game->map)[i] == '0' || (game->map)[i] == 'P')
		print_image(game, &(game->i.floor), xy, i);
	else if ((game->map)[i] == 'C')
	{
		print_image(game, &(game->i.floor), xy, i);
		print_image(game, &(game->i.redbull), xy, i);
	}
	else if ((game->map)[i] == 'E')
	{
		print_image(game, &(game->i.floor), xy, i);
		xy.y -= 10;
		print_image(game, &(game->i.lady), xy, i);
	}
}

int	map(t_root *game)
{	
	t_vector	xy;
	int			i;
	t_image		*player;

	player = &(game->i.max);
	xy.x = 0;
	xy.y = 0;
	i = 0;
	while ((game->map)[i])
	{
		if ((game->map)[i] == '\n')
		{
			xy.x = 0;
			xy.y += game->i.floor.size.y;
		}
		else
		{
			symbol_to_image(game, xy, i);
			xy.x += game->i.floor.size.x;
		}
		i++;
	}
	print_image(game, player, game->i.max.pixel_loc, i);
	return (1);
}
