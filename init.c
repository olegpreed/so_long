/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 19:52:53 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerlocation(t_root *game)
{
	int	xy;
	int	w;
	int	h;

	w = game->floor.size.x;
	h = game->floor.size.y;
	xy = ft_strchr(game->map, 'P') - game->map;
	game->max.symbol_loc.y = xy / (game->symbolsize.x + 1);
	game->max.symbol_loc.x = xy % (game->symbolsize.x + 1);
	game->max.pixel_loc.y = game->max.symbol_loc.y * h;
	game->max.pixel_loc.x = game->max.symbol_loc.x * w;
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
	game->floor.path = "./images/floor.xpm";
	game->floor.reference = image_ref(game, &(game->floor));
	game->wall.path = "./images/wall.xpm";
	game->wall.reference = image_ref(game, &(game->wall));
	game->ball.path = "./images/speakerd.xpm";
	game->ball.reference = image_ref(game, &(game->ball));
	game->lady.path = "./images/lady.xpm";
	game->lady.reference = image_ref(game, &(game->lady));
	game->max.path = "./images/max.xpm";
	game->max.reference = image_ref(game, &(game->max));
	playerlocation(game);
}

void	count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->floor.size.x;
	game->pixelsize.y = game->symbolsize.y * game->floor.size.y;
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
