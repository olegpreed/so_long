/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 19:31:00 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	playerlocation(t_root *game)
{
	int	xy;
	int	w;
	int	h;

	w = game->i.floor.size.x;
	h = game->i.floor.size.y;
	if (game->status == WIN || game->status == RECORD)
		xy = ft_strchr(game->map, 'L') - game->map;
	else
		xy = ft_strchr(game->map, 'P') - game->map;
	game->i.max.symbol_loc.y = xy / (game->symbolsize.x + 1);
	game->i.max.symbol_loc.x = xy % (game->symbolsize.x + 1);
	game->i.max.pixel_loc.y = game->i.max.symbol_loc.y * h - 10;
	game->i.max.pixel_loc.x = game->i.max.symbol_loc.x * w;
	game->i.max.symbol_index = xy;
}

void	get_high_score(t_root *game)
{
	int		j;
	char	*s;

	j = 0;
	j = (game->m.lvl - 1) * 5;
	s = ft_substr(&(game->scoreboard[j]), 0, 5);
	game->record = ft_atoi(s);
	free(s);
}

int	scoreboard(t_root *game)
{
	int		k;
	char	*string[2];

	k = 1;
	game->fd = open("scores/scoreboard", O_RDWR);
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

void	start(t_root *game, int a)
{
	int	x;
	int	y;

	if (!a)
		sprites_init(game);
	game->i.lady.pixels = ft_strchr(game->map, 'E');
	playerlocation(game);
	game->pixelsize.x = game->symbolsize.x * game->i.floor.size.x;
	game->pixelsize.y = game->symbolsize.y * game->i.floor.size.y;
	scoreboard(game);
	x = game->pixelsize.x;
	y = game->pixelsize.y;
	game->mlxw = mlx_new_window(game->mlx, x, y, level_name(game->m.lvl));
	game->i.max_o.symbol_index = 0;
	game->m.select.pixel_loc.x = 0;
	game->close_level = 0;
	if (game->restart != 1)
		game->restart = 0;
	game->score = 0;
	game->p_status = SOBER;
}
