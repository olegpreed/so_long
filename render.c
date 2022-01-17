/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/01/17 22:30:23 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_image(t_root *game, t_image *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlxw, image->reference, x, y);
}

void	symbol_to_image(t_root *game, int x, int y, int i)
{
	if ((game->map)[i] == '1')
		print_image(game, &(game->wall), x, y);
	else if ((game->map)[i] == '0' || (game->map)[i] == 'P')
		print_image(game, &(game->grass), x, y);
	else if ((game->map)[i] == 'C')
	{
		print_image(game, &(game->grass), x, y);
		print_image(game, &(game->ball), x + 25, y + 25);
	}
	else if ((game->map)[i] == 'E')
	{
		print_image(game, &(game->grass), x, y);
		print_image(game, &(game->pika), x, y);
	}
}

int	map(t_root *game)
{	
	int		x;
	int		y;
	int		i;
	t_image	*player;

	player = &(game->ash);
	x = 0;
	y = 0;
	i = 0;
	while ((game->map)[i])
	{
		if ((game->map)[i] == '\n')
		{
			x = 0;
			y += game->grass.size.y;
		}
		else
		{
			symbol_to_image(game, x, y, i);
			x += game->grass.size.x;
		}
		i++;
	}
	print_image(game, player, game->ash.pixel_loc.x, game->ash.pixel_loc.y);
	return (1);
}
