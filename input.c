/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/01/17 22:47:35 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	action(int keypress, t_root *game)
{
	static int	xx;
	static int	yy;
	static int	count;
	xx = game->ash.symbol_loc.x;
	yy = game->ash.symbol_loc.y;
	if (keypress == W && game->map[xx + (game->symbolsize.x + 1) * (yy - 1)] != '1')
	{
		game->ash.symbol_loc.y -= 1; 
		game->ash.pixel_loc.y -= game->grass.size.y; 
		count++;
	}
	else if (keypress == A && game->map[(xx - 1) + (game->symbolsize.x + 1) * yy] != '1')
	{
		game->ash.pixel_loc.x -= game->grass.size.x; 
		game->ash.symbol_loc.x -= 1; 
		count++;
	}
	else if (keypress == S && game->map[xx + (game->symbolsize.x + 1) * (yy + 1)] != '1')
	{
		game->ash.symbol_loc.y += 1; 
		game->ash.pixel_loc.y += game->grass.size.y; 
		count++;
	}
	else if (keypress == D && game->map[(xx + 1) + (game->symbolsize.x + 1) * yy] != '1')
	{
		game->ash.pixel_loc.x += game->grass.size.x;
		game->ash.symbol_loc.x += 1; 
		count++;
	} 		
	else if (keypress == Esc_key)
	{
		mlx_destroy_window(game->mlx, game->mlxw);
		game->close = 1;
		return (1);
	}
	printf("Move count: %d\n", count);
	return (0);
}
