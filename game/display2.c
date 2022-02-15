/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:19:36 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:09:35 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sprite_float(void)
{
	static int	i;
	static int	k;
	static int	count;

	if (count % 5 == 0)
	{
		if (i == 0)
			k = 0;
		if (i == 5)
			k = 1;
		if (!k)
			i++;
		if (k)
			i--;
	}
	count++;
	return (i);
}

int	lady(t_root *game, t_vector xy, int i)
{
	print_image(game, &(game->i.floor), xy, i);
	xy.y -= 10;
	if (!game->k)
		xy.y += 3;
	if (*game->i.lady.pixels == 'E')
		print_image(game, &(game->i.lady), xy, i);
	if (*game->i.lady.pixels == 'L')
		print_image(game, &(game->i.lady_w), xy, i);
	return (sprite_float());
}

void	collectible(t_root *game, t_vector xy, int i, int j)
{
	print_image(game, &(game->i.floor_c), xy, i);
	xy.y -= 25;
	print_image(game, &(game->i.shadow_b), xy, i);
	xy.y -= j;
	if (!game->cheat)
		print_image(game, &(game->i.beer), xy, 0);
	else
	{
		xy.x += 26;
		xy.y += 5;
		print_image(game, &(game->i.redbull), xy, 0);
	}
}

void	player(t_root *game, t_vector xy, int i)
{
	print_image(game, &(game->i.floor), xy, i);
	xy.y -= 10;
	if (game->p_status == SOBER)
		print_image(game, &(game->i.max), xy, 0);
	if (game->p_status == DRUNK)
		print_image(game, &(game->i.max_d), xy, 0);
}

void	walls(t_root *game, t_vector xy, int i, int k)
{
	int			x;
	int			y;
	char		*map;

	map = game->map;
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	if (map[i] == '1' && (i - x) <= 0 && map[i - 1] != 'D' && !k)
		print_image(game, &(game->i.speak), xy, i);
	else if (map[i] == '1' && (i - x) <= 0 && map[i - 1] != 'D' && k)
		print_image(game, &(game->i.speak2), xy, i);
	else if (map[i] == 'D')
		dj(game, xy);
	else if (map[i] == '1' && (i - x) > 0 && ((x + 1) * y) - i > (x + 1))
		print_image(game, &(game->i.c.coke[0]), xy, i);
	else if (map[i] == '1' && (i - x) > 0 && ((x + 1) * y) - i <= (x + 1))
		print_image(game, &(game->i.wall), xy, i);
}
