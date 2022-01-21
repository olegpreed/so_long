/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:31:28 by preed             #+#    #+#             */
/*   Updated: 2022/01/21 16:20:26 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	*(unsigned int*)dst = color;
}