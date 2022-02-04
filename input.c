/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:45:30 by preed             #+#    #+#             */
/*   Updated: 2022/02/04 21:44:06 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drink(char a, int *k)
{
	static int	c;

	if (a == 's')
	{
		while (c < 3)
		{
			c++;
			return (1);
		}
	}
	*k = 0;
	c = 0;
	return (0);
}

void	move_sd(t_root *game, char key, int *count, int j)
{
	int	*i;
	int	line;
	static int	k;
	int	c;

	c = 0;
	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 's')
	{
		if (game->map[j + game->symbolsize.x + 1] == 'C')
			k = 1;
		if (k)
			c = drink('s', &(k));
		game->map[j + game->symbolsize.x + 1] = 'P';
		game->map[j] = '0';
		game->i.max.symbol_loc.y += 1;
		game->i.max.pixel_loc.y += game->i.floor.size.y;
		if (!c)
			game->i.max.reference = image_ref(game, &(game->i.max));
		else
			game->i.max.reference = image_ref(game, &(game->i.max_d));
		game->i.max.symbol_index += (game->symbolsize.x + 1);
	}
	else if (key == 'd')
	{
		game->map[j + 1] = 'P';
		game->map[j] = '0';
		game->i.max.pixel_loc.x += game->i.floor.size.x;
		game->i.max.symbol_loc.x += 1;
		game->i.max.reference = image_ref(game, &(game->i.max_r));
		game->i.max.symbol_index += 1;
	}
	*i = symbol_loc(game, line);
	(*count)++;
	printf("Move count: %d\n%d", *count, game->i.max.symbol_index);
}

void	move_wa(t_root *game, char key, int *count, int j)
{
	int	*i;
	int	line;

	line = game->symbolsize.x;
	i = &(game->i.max.symbol_index);
	if (key == 'w')
	{
		game->map[j - game->symbolsize.x - 1] = 'P';
		game->map[j] = '0';
		game->i.max.symbol_loc.y -= 1;
		game->i.max.pixel_loc.y -= game->i.floor.size.y;
		game->i.max.reference = image_ref(game, &(game->i.max_b));
		game->i.max.symbol_index -= (game->symbolsize.x + 1);
	}
	else if (key == 'a')
	{
		game->map[j - 1] = 'P';
		game->map[j] = '0';
		game->i.max.pixel_loc.x -= game->i.floor.size.x;
		game->i.max.symbol_loc.x -= 1;
		game->i.max.reference = image_ref(game, &(game->i.max_l));
		game->i.max.symbol_index -= 1;
	}
	*i = symbol_loc(game, line);
	(*count)++;
	printf("Move count: %d\n", *count);
}

int	exit_game(void)
{
	exit(0);
	return (1);
}

int	action(int keypress, t_root *game)
{
	static int	xx;
	static int	yy;
	static int	count;
	int			line;
	int i;

	xx = game->i.max.symbol_loc.x;
	yy = game->i.max.symbol_loc.y;
	line = game->symbolsize.x;
	if (!ft_strchr(game->map, 'C'))
		*game->i.lady.pixels = 'L';
	i = ft_strchr(game->map, 'P') - game->map;
	if (keypress == ESC)
	{
		mlx_destroy_window(game->mlx, game->mlxw);
		exit(0);
	}
	if (game->over == 0)
	{
		if (keypress == W && game->map[xx + (line + 1) * (yy - 1)] != '1' && game->map[xx + (line + 1) * (yy - 1)] != 'D' && game->map[xx + (line + 1) * (yy - 1)] != 'E')
			move_wa(game, 'w', &count, i);
		else if (keypress == A && game->map[(xx - 1) + (line + 1) * yy] != '1' && game->map[(xx - 1) + (line + 1) * yy] != 'E')
			move_wa(game, 'a', &count, i);
		else if (keypress == S && game->map[xx + (line + 1) * (yy + 1)] != '1' && game->map[xx + (line + 1) * (yy + 1)]  != 'E')
			move_sd(game, 's', &count, i);
		else if (keypress == D && game->map[(xx + 1) + (line + 1) * yy] != '1' && game->map[(xx + 1) + (line + 1) * yy] != 'E')
			move_sd(game, 'd', &count, i);
		if (ft_strchr(game->map, 'P') == game->i.lady.pixels && !ft_strchr(game->map, 'C'))
			win(game);
	}
	if (keypress == 36)
		{
			game->over = 0;
			free(game->map);
			//start(game);
			game->map = ft_strdup(game->copy_map);
			playerlocation(game);
			game->i.max_o.symbol_index = 0;
			patrol_init(game);
			*game->i.lady.pixels = 'E';
		}
	//printf("%s\n", game->map);
	return (0);
}
