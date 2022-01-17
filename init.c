/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:40:46 by preed             #+#    #+#             */
/*   Updated: 2022/01/17 22:28:02 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerlocation(t_root *game)
{
	int	xy;
	int	w;
	int	h;

	w = game->grass.size.x;
	h = game->grass.size.y;
	xy = ft_strchr(game->map, 'P') - game->map;
	game->ash.symbol_loc.y = xy / (game->symbolsize.x + 1);
	game->ash.symbol_loc.x = xy % (game->symbolsize.x + 1);
	game->ash.pixel_loc.y = game->ash.symbol_loc.y * h;
	game->ash.pixel_loc.x = game->ash.symbol_loc.x * w;
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
	game->grass.path = "./images/grass.xpm";
	game->grass.reference = image_ref(game, &(game->grass));
	game->wall.path = "./images/wall.xpm";
	game->wall.reference = image_ref(game, &(game->wall));
	game->ball.path = "./images/pokeball.xpm";
	game->ball.reference = image_ref(game, &(game->ball));
	game->pika.path = "./images/pikachu.xpm";
	game->pika.reference = image_ref(game, &(game->pika));
	game->ash.path = "./images/ash.xpm";
	game->ash.reference = image_ref(game, &(game->ash));
	playerlocation(game);
}

void	count_map(t_root *game)
{	
	game->pixelsize.x = game->symbolsize.x * game->grass.size.x;
	game->pixelsize.y = game->symbolsize.y * game->grass.size.y;
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
