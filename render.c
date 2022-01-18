/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:03:56 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 19:48:52 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_image(t_root *game, t_image *image, int x, int y)
{
	int		*i;
	t_image	*max;

	max = &(game->max);
	i = &(game->max.symbol_index);
	if (image == max && game->map[game->max.symbol_index] == 'C')
		game->map[game->max.symbol_index] = '0';
	if (image == max && game->map[*i] == 'E' && !ft_strchr(game->map, 'C'))
		exit_game();
	mlx_put_image_to_window(game->mlx, game->mlxw, image->reference, x, y);
}

void	symbol_to_image(t_root *game, int x, int y, int i)
{
	if ((game->map)[i] == '1')
		print_image(game, &(game->wall), x, y);
	else if ((game->map)[i] == '0' || (game->map)[i] == 'P')
		print_image(game, &(game->floor), x, y);
	else if ((game->map)[i] == 'C')
	{
		print_image(game, &(game->floor), x, y);
		print_image(game, &(game->ball), x, y);
	}
	else if ((game->map)[i] == 'E')
	{
		print_image(game, &(game->floor), x, y);
		print_image(game, &(game->lady), x, y);
	}
}

int	map(t_root *game)
{	
	int		x;
	int		y;
	int		i;
	t_image	*player;

	player = &(game->max);
	x = 0;
	y = 0;
	i = 0;
	while ((game->map)[i])
	{
		if ((game->map)[i] == '\n')
		{
			x = 0;
			y += game->floor.size.y;
		}
		else
		{
			symbol_to_image(game, x, y, i);
			x += game->floor.size.x;
		}
		i++;
	}
	print_image(game, player, game->max.pixel_loc.x, game->max.pixel_loc.y);
	return (1);
}
