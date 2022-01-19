/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/01/19 20:05:52 by preed            ###   ########.fr       */
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

void	sprites_init(t_root *game)
{
	game->i.floor.path = "./images/floor.xpm";
	game->i.floor.reference = image_ref(game, &(game->i.floor));
	game->i.condom.path = "./images/condom.xpm";
	game->i.condom.reference = image_ref(game, &(game->i.condom));
	game->i.dj.path = "./images/dj.xpm";
	game->i.dj.reference = image_ref(game, &(game->i.dj));
	game->i.redbull.path = "./images/redbull.xpm";
	game->i.redbull.reference = image_ref(game, &(game->i.redbull));
	game->i.lady.path = "./images/lady.xpm";
	game->i.lady.reference = image_ref(game, &(game->i.lady));
	game->i.max.path = "./images/max.xpm";
	game->i.max.reference = image_ref(game, &(game->i.max));
	game->i.speak.path = "./images/speaker.xpm";
	game->i.speak.reference = image_ref(game, &(game->i.speak));
	game->i.coke.path = "./images/coke.xpm";
	game->i.coke.reference = image_ref(game, &(game->i.coke));
	game->i.goth.path = "./images/goth.xpm";
	game->i.goth.reference = image_ref(game, &(game->i.goth));
	game->i.hair.path = "./images/hair.xpm";
	game->i.hair.reference = image_ref(game, &(game->i.hair));
	game->i.naked.path = "./images/naked.xpm";
	game->i.naked.reference = image_ref(game, &(game->i.naked));
	game->i.rapper.path = "./images/rapper.xpm";
	game->i.rapper.reference = image_ref(game, &(game->i.rapper));
	game->i.wall.path = "./images/wall.xpm";
	game->i.wall.reference = image_ref(game, &(game->i.wall));
	game->i.door.path = "./images/door.xpm";
	game->i.door.reference = image_ref(game, &(game->i.door));
	playerlocation(game);
}

void	count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->i.floor.size.x;
	game->pixelsize.y = game->symbolsize.y * game->i.floor.size.y;
}

void	start(t_root *game)
{
	int	x;
	int	y;

	sprites_init(game);
	count_map(game);
	x = game->pixelsize.x;
	y = game->pixelsize.y;
	game->mlxw = mlx_new_window(game->mlx, x, y, "Approach");
}
