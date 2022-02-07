/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/02/07 19:27:01 by oleg             ###   ########.fr       */
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

void	snumbers_init(t_root *game)
{
	game->i.snumbers[0].path = "./images/0s.xpm";
	game->i.snumbers[0].reference = image_ref(game, &(game->i.snumbers[0]));
	game->i.snumbers[1].path = "./images/1s.xpm";
	game->i.snumbers[1].reference = image_ref(game, &(game->i.snumbers[1]));
	game->i.snumbers[2].path = "./images/2s.xpm";
	game->i.snumbers[2].reference = image_ref(game, &(game->i.snumbers[2]));
	game->i.snumbers[3].path = "./images/3s.xpm";
	game->i.snumbers[3].reference = image_ref(game, &(game->i.snumbers[3]));
	game->i.snumbers[4].path = "./images/4s.xpm";
	game->i.snumbers[4].reference = image_ref(game, &(game->i.snumbers[4]));
	game->i.snumbers[5].path = "./images/5s.xpm";
	game->i.snumbers[5].reference = image_ref(game, &(game->i.snumbers[5]));
	game->i.snumbers[6].path = "./images/6s.xpm";
	game->i.snumbers[6].reference = image_ref(game, &(game->i.snumbers[6]));
	game->i.snumbers[7].path = "./images/7s.xpm";
	game->i.snumbers[7].reference = image_ref(game, &(game->i.snumbers[7]));
	game->i.snumbers[8].path = "./images/8s.xpm";
	game->i.snumbers[8].reference = image_ref(game, &(game->i.snumbers[8]));
	game->i.snumbers[9].path = "./images/9s.xpm";
	game->i.snumbers[9].reference = image_ref(game, &(game->i.snumbers[9]));
}

void	sprites_init(t_root *game)
{
	int i = 0;

	game->i.floor.path = "./images/floor.xpm";
	game->i.floor.reference = image_ref(game, &(game->i.floor));
	game->i.floor_w.path = "./images/tile_w.xpm";
	game->i.floor_w.reference = image_ref(game, &(game->i.floor_w));
	game->i.floor_c.path = "./images/tile2.xpm";
	game->i.floor_c.reference = image_ref(game, &(game->i.floor_c));
	game->i.dj.path = "./images/dj.xpm";
	game->i.dj.reference = image_ref(game, &(game->i.dj));
	game->i.dj2.path = "./images/dj2.xpm";
	game->i.dj2.reference = image_ref(game, &(game->i.dj2));
	game->i.dj3.path = "./images/dj3.xpm";
	game->i.dj3.reference = image_ref(game, &(game->i.dj3));
	game->i.redbull.path = "./images/redbull.xpm";
	game->i.redbull.reference = image_ref(game, &(game->i.redbull));
	game->i.lady.path = "./images/lady.xpm";
	game->i.lady.reference = image_ref(game, &(game->i.lady));
	game->i.lady_w.path = "./images/lady_w.xpm";
	game->i.lady_w.reference = image_ref(game, &(game->i.lady_w));
	game->i.lady.pixels = ft_strchr(game->map, 'E');
	game->i.max.path = "./images/max.xpm";
	game->i.max.reference = image_ref(game, &(game->i.max));
	game->i.max_o.path = "./images/max_over.xpm";
	game->i.max_o.reference = image_ref(game, &(game->i.max_o));
	game->i.max_o.pixel_loc.x = 0;
	game->i.max_o.pixel_loc.y = 0;
	game->i.max_l.path = "./images/max_l.xpm";
	game->i.max_l.reference = image_ref(game, &(game->i.max_l));
	game->i.max_r.path = "./images/max_r.xpm";
	game->i.max_r.reference = image_ref(game, &(game->i.max_r));
	game->i.max_b.path = "./images/max_b.xpm";
	game->i.max_b.reference = image_ref(game, &(game->i.max_b));
	game->i.max_d.path = "./images/max_d.xpm";
	game->i.max_d.reference = image_ref(game, &(game->i.max_d));
	game->i.speak.path = "./images/speaker.xpm";
	game->i.speak.reference = image_ref(game, &(game->i.speak));
	game->i.speak2.path = "./images/speaker2.xpm";
	game->i.speak2.reference = image_ref(game, &(game->i.speak2));
	while (i < game->t_count)
	{
		game->thug[i].path = "./images/thug.xpm";
		game->thug[i].reference = image_ref(game, &(game->thug[i]));
		i++;
	}
	game->i.c.coke[0].path = "./images/coke.xpm";
	game->i.c.coke[0].reference = image_ref(game, &(game->i.c.coke[0]));
	game->i.c.goth[0].path = "./images/goth.xpm";
	game->i.c.goth[0].reference = image_ref(game, &(game->i.c.goth[0]));
	game->i.c.goth[1].path = "./images/goth2.xpm";
	game->i.c.goth[1].reference = image_ref(game, &(game->i.c.goth[1]));
	game->i.c.hair[0].path = "./images/hair.xpm";
	game->i.c.hair[0].reference = image_ref(game, &(game->i.c.hair[0]));
	game->i.c.hair[1].path = "./images/hair2.xpm";
	game->i.c.hair[1].reference = image_ref(game, &(game->i.c.hair[1]));
	game->i.c.naked[0].path = "./images/naked.xpm";
	game->i.c.naked[0].reference = image_ref(game, &(game->i.c.naked[0]));
	game->i.c.naked[1].path = "./images/naked2.xpm";
	game->i.c.naked[1].reference = image_ref(game, &(game->i.c.naked[1]));
	game->i.c.tired[0].path = "./images/tired.xpm";
	game->i.c.tired[0].reference = image_ref(game, &(game->i.c.tired[0]));
	game->i.c.tired[1].path = "./images/tired2.xpm";
	game->i.c.tired[1].reference = image_ref(game, &(game->i.c.tired[1]));
	game->i.c.rapper[0].path = "./images/rapper.xpm";
	game->i.c.rapper[0].reference = image_ref(game, &(game->i.c.rapper[0]));
	game->i.c.rapper[1].path = "./images/rapper2.xpm";
	game->i.c.rapper[1].reference = image_ref(game, &(game->i.c.rapper[1]));
	game->i.wall.path = "./images/wall.xpm";
	game->i.wall.reference = image_ref(game, &(game->i.wall));
	game->i.door.path = "./images/door.xpm";
	game->i.door.reference = image_ref(game, &(game->i.door));
	game->i.door_o.path = "./images/door_o.xpm";
	game->i.door_o.reference = image_ref(game, &(game->i.door_o));
	game->i.beer.path = "./images/beer.xpm";
	game->i.beer.reference = image_ref(game, &(game->i.beer));
	game->i.fence.path = "./images/fence.xpm";
	game->i.fence.reference = image_ref(game, &(game->i.fence));
	game->i.shadow_b.path = "./images/shadow_b.xpm";
	game->i.shadow_b.reference = image_ref(game, &(game->i.shadow_b));
	game->i.gameover.path = "./images/gameover.xpm";
	game->i.gameover.reference = image_ref(game, &(game->i.gameover));
	snumbers_init(game);
	playerlocation(game);
}

void	count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->i.floor.size.x;
	game->pixelsize.y = game->symbolsize.y * game->i.floor.size.y;
}

void	level_name(t_root *game, int x, int y)
{
	if (game->m.lvl == 1)
		game->mlxw = mlx_new_window(game->mlx, x, y, "First time in the club");
	else
		game->mlxw = mlx_new_window(game->mlx, x, y, "Approach");
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
