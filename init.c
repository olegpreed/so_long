/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/02/10 16:34:12 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerlocation(t_root *game)
{
	int	xy;
	int	w;
	int	h;

	w = game->i.floor.size.x;
	h = game->i.floor.size.y;
	if (game->over == 21 || game->over == 100)
		xy = ft_strchr(game->map, 'L') - game->map;
	else
		xy = ft_strchr(game->map, 'P') - game->map;
	game->i.max.symbol_loc.y = xy / (game->symbolsize.x + 1);
	game->i.max.symbol_loc.x = xy % (game->symbolsize.x + 1);
	game->i.max.pixel_loc.y = game->i.max.symbol_loc.y * h - 10;
	game->i.max.pixel_loc.x = game->i.max.symbol_loc.x * w;
	game->i.max.symbol_index = xy;
}
// w : sprite width
// h : sprite height

void	*image_ref(t_root *game, t_image *image)
{
	void	*p;
	void	*mlx;
	char	*path;

	mlx = game->mlx;
	path = image->path;
	p = mlx_xpm_file_to_image(mlx, path, &(image->size.x), &(image->size.y));
	return (p);
}

void	count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->i.floor.size.x;
	game->pixelsize.y = game->symbolsize.y * game->i.floor.size.y;
}

void	level_name(t_root *game, int x, int y)
{
	if (game->m.lvl == 1)
		game->mlxw = mlx_new_window(game->mlx, x, y, "01 - First time in the club");
	else
		game->mlxw = mlx_new_window(game->mlx, x, y, "02 - Approach");
}

void	get_high_score(t_root *game)
{
	int	i;
	int j;
	char *s;

	i = 0;
	j = 0;
	while(i < game->m.lvl - 1)
	{
		if (game->scoreboard[j++] == '\n')
			i++;
	}
	i = ft_strlen_n(&(game->scoreboard[j]));
	s = ft_substr(&(game->scoreboard[j]), 0, i);
	game->record = ft_atoi(s);
	free(s);
	printf("record is : %d\n", game->record);
}

int	scoreboard(t_root *game)
{
	int		k;
	char	*string[2];

	k = 1;
	game->fd = open("scoreboard", O_RDWR);
	if (game->fd == -1)
		return (1);
	game->scoreboard = get_next_line(game->fd);
	while (k)
	{
		string[0] = game->scoreboard;
		string[1] = get_next_line(game->fd);
		if (string[1])
		{
			game->scoreboard = ft_strjoin(game->scoreboard, string[1]);
			free(string[0]);
			free(string[1]);
		}
		else
			k = 0;
	}
	get_high_score(game);
	close(game->fd);
	return (0);
}

void	start(t_root *game)
{
	int	x;
	int	y;

	sprites_init(game);
	count_map(game);
	scoreboard(game);
	x = game->pixelsize.x;
	y = game->pixelsize.y;
	level_name(game, x, y);
	game->i.max_o.symbol_index = 0;
	game->m.select.pixel_loc.x = 0;
	game->close_level = 0;
	game->restart = 0;
	game->score = 0;
}
